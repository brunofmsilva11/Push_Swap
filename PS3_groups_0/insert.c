/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:58:11 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/28 01:18:24 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//inserir num no inicio da lista
void    insert_top(t_node **lista, int num){
    t_node *new = malloc(sizeof(t_node));
    //t_node *aux = malloc(sizeof(t_node));
    if(new){
        new->value = num;
        new->next = *lista;
        *lista = new;
    }
    else
        printf("Erro a alocar a memoria!\n");
    //free(new);
    //free(aux);
}

//inserir num no fim da lista
void    insert_end(t_node **lista, int num) {
    t_node *new = malloc(sizeof(t_node));

    if (new) {
        new->value = num;
        new->next = NULL;

        // Verificar se é o primeiro valor da lista
        if (*lista == NULL) {
            *lista = new;
        }
        else 
        {
            t_node *aux = *lista;
            while (aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = new;
        }
    } else {
        printf("Erro a alocar memoria!\n");
    }
}


//inserir num no meio da lista
void    insert_mid(t_node **lista, int num, int pre){
    t_node *new = malloc(sizeof(t_node));
    t_node *aux = malloc(sizeof(t_node));

    if(new){
        new->value = num;
        //verificar se e o primeiro value da lista
        if(*lista == NULL){
            new->next = NULL;
            *lista = new;
        }
        else{
            aux = *lista;
            while(aux->value != pre && aux->next != NULL)
                aux = aux->next;
            new->next = aux->next;
            aux->next = new;
        }
    }
    else
        printf("Erro a alocar memoria!\n");
    //free(new);
    //free(aux);
}
