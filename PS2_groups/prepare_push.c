/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 14:15:12 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/16 15:45:13 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_min_max(Node **listB, t_utils *utils)
{
	if (utils->nb_index_b > (utils->len_b / 2))//Verifica se o maximo esta na segunda metade e envia o de baixo para o topo
	{
		while ((*listB)->value != utils->max)//Enviamos o max sempre para o topo de B
		{
			rrb(listB);
			//utils->rrb++;
		}
	}
	else//Como o max esta na primeira metade da lista B usamos rb que envia o primeiro para baixo
	{
		while ((*listB)->value != utils->max)//Envia o max para o topo de B
		{
			rb(listB);
			//utils->rb++;
		}
	}
}

void	rotate_default(Node **listA, Node **listB, t_utils *utils)
{
	if (utils->nb_index_b > (utils->len_b / 2))
	{
		while (!((*listA)->value > (*listB)->value
				&& (*listA)->value < (*listB)->prev->value))
		{
			rrb(listB);
			//utils->rrb++;
		}
	}
	else
	{
		while (!((*listA)->value > (*listB)->value
				&& (*listA)->value < (*listB)->prev->value))
		{
			rb(listB);
			//utils->rb++;
		}
	}
}

void	prepare_to_push_2(Node **listA, t_utils *utils, int i)//Verificamos em que parte da lista esta o numero
{
	if (i > (utils->len_a / 2))
	{
		while ((*listA)->value != utils->nb)
		{
			rra(listA);
			//utils->rra++;
		}
	}
	else
	{
		while ((*listA)->value != utils->nb)
		{
			ra(listA);
			//utils->ra++;
		}
	}
}

void	prepare_to_push(Node **listA, Node **listB, t_utils *utils)
{
	Node	*node;
	int		i;

	node = (*listA);
	i = 0;
	while (node->value != utils->nb)
	{
		node = node->next;
		i++;
	}
	prepare_to_push_2(listA, utils, i);
	if ((*listA)->value < utils->max && (*listA)->value > utils->min)
		rotate_default(listA, listB, utils);
	else
		rotate_min_max(listB, utils);
	//print_rotations(utils);
	pb(listB, listA);
}