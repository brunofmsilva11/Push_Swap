#include "push_swap.h"

void    init_stack(t_utils *stack)
{
    stack->listA = NULL;
    stack->listB = NULL;
    stack->max_bits = 0;
    stack->max = 0;
    stack->min = 0;
}

int main(int ac, char **av)
{
    t_utils *stack;
    stack = malloc(sizeof(t_utils));
    int i = 1;
    
    if(ac < 2)
        exit(1);
    init_stack(stack);
    while(av[i] != NULL)
    {
        Node *new_node = malloc(sizeof(Node));
        new_node->value = atoi(av[i]);
        new_node->next = NULL;
        if(stack->listA == NULL)
            stack->listA = new_node;
        else
        {
            Node *aux = stack->listA;
            while(aux->next)
                aux = aux->next;
            aux->next = new_node;
        }
        i++;
    }
    Node *tmp = stack->listA;
    while(tmp->next)
    {
        tmp->next->prev = tmp;
        tmp = tmp->next;
    }
    stack->listA->prev = tmp;
    if(lstsize(stack->listA) > 5)
        ord(stack);
    else
        simple(stack);
    tmp = stack->listA;
    while(tmp != NULL){
        if(tmp->next == NULL)
            printf("%d!", tmp->value);
        else
            printf("%d - ", tmp->value);
        tmp = tmp->next;
    }
    return (1);
}