/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:03:44 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/25 01:16:33 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//PUSH
void    push(t_node **list_to, t_node **list_from)
{
    t_node *aux = malloc(sizeof(t_node));
    aux = *list_from;
    insert_top(list_to, aux->value);
    *list_from = aux->next;
    //free(aux);
}

void    pa(t_utils *stack)
{
    push(&stack->listA, &stack->listB);
    write(1, "pa\n", 3);
}

void    pb(t_utils *stack)
{
    push(&stack->listB, &stack->listA);
    write(1, "pb\n", 3);
}
