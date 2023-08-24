/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:00:58 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/18 13:33:14 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void imprimirA(t_node *node)
{
    printf("ListaA:\n");
    while (node){
        printf("%d\n", node->value);
        node = node->next;
    }
}

void imprimirB(t_node *node)
{
    printf("ListaB:\n");
    while (node){
        printf("%d\n", node->value);
        node = node->next;
    }
}