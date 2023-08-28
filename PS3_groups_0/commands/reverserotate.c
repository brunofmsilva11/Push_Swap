/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:03:27 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/28 01:12:30 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//REVERSEROTATE
void    reverse_rotate(t_node **node)
{
    int tmp;
    t_node *aux = malloc(sizeof(t_node));
    //t_node *rem = NULL;
    aux = *node;
    while(aux->next){
        aux = aux->next;
    }
    tmp = aux->value;
    insert_top(node, tmp);
    remove_node(node, tmp);
    //free(aux);
}

void    rra(t_utils *stack)
{
    reverse_rotate(&stack->listA);
    write(1, "rra\n", 4);
}

void    rrb(t_utils *stack)
{
    reverse_rotate(&stack->listB);
    write(1, "rrb\n", 4);
}

void    rrr(t_utils *stack)
{
    reverse_rotate(&stack->listA);
    reverse_rotate(&stack->listB);
    write(1, "rrr\n", 4);
}

void    remove_node(t_node **node, int num)
{
    t_node *aux = NULL;
    t_node *remove = NULL;

    aux = *node;
    while((aux->next != NULL) && (aux->next->value != num))
        aux = aux->next;
    if(aux->next)//verifica se o proximo value existe depois do while
    {
        remove = aux->next;
        aux->next = remove->next;
    }
    free(remove);
}