#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

int main(int ac, char **av)
{
    Node *lista = NULL;//criamos a lista

    printf("Digite os elementos da lista (digite '-1' para parar):\n");
    int input;
    while (1) {
        scanf("%d", &input);
        if (input == -1) {
            break;
        }

        Node *newNode = malloc(sizeof(Node));//serve para alocar a memoria do valor que vamos inserir no novo no
        /* if (newNode == NULL) {
            printf("Erro na alocação de memória.\n");
            exit(1);
        } */

        //Aqui queremos colocar o novo No no inicio da lista
        newNode->value = input;
        newNode->next = lista;//[Novo No]-->lista[[No][No][No][NULL]]
        lista = newNode;//neste a lista recebe o novo no que aponta para a lista antiga

        /* Aqui queremos colocar o novo No no fim da lista
        newNode->value = input;
        newNode->next = NULL;//como sabemos que queremos colocar no fim colocamos logo a apontar para NULL
        if (lista == NULL)//verificamos se a lista esta vazia e se estamos a inserir o primeiro no 
        {
            lista = newNode;
        } 
        else {
            Node *temp = lista;//Temos de cria um No temporario para percorrer a lista toda porque se usarmos a variavel lista perdemos os valores para tras
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;//lista[[No][No][No]"[Novo No]"[NULL]] nao esquecer que ja tinhamos declarado em cima que o newnode->next = NULL
        } */
    }

    printf("Lista criada: ");
    Node *temp = lista;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");

    // Liberar memória alocada pela lista
    while (lista != NULL) {
        Node *temp = lista;
        lista = lista->next;
        free(temp);
    }
}