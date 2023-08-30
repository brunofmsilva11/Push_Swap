/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:26:58 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/30 11:46:39 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_utils *stack)
{
	stack->list_a = NULL;
	stack->list_b = NULL;
	stack->max_bits = 0;
	stack->max = 0;
	stack->min = 0;
	stack->max_b = 0;
	stack->third = 0;
}

int	is_sorted(t_node *list)
{
	t_node	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
