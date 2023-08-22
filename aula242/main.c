/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:42:54 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/18 13:32:05 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    main(int ac, char **av){
    t_node *listaA = NULL;
    t_node *listaB = NULL;
    int i = 1;
    
    if(ac < 2)
        exit(1);
    while(av[i] != NULL){
        t_node *new = malloc(sizeof(t_node));
        new->value = atoi(av[i]);
        new->next = NULL;
        if(listaA == NULL)
            listaA = new;
        else{
            t_node *aux = listaA;
            while(aux->next){
                aux = aux->next;
            }
            aux->next = new;
        }
        i++;
    }
    t_node *tmp = listaA;
    //printf("Lista:\t");
    while(tmp->next != NULL){
        tmp->next->prev = tmp;
        tmp = tmp->next;
    }
    listaA->prev = tmp;
    if(lstsize(listaA) > 5)
        sort_big(&listaA, &listaB);
    else
        simple(&listaA, &listaB);
    printf("\n");
    tmp = listaA;
    while(tmp != NULL){
        if(tmp->next == NULL)
            printf("%d!", tmp->value);
        else
            printf("%d - ", tmp->value);
        tmp = tmp->next;
    }
}