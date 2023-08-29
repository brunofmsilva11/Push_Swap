/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:52:44 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 16:31:24 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_next_min(t_utils *stack)
{
	t_node	*tmp;
	int		next_min;

	tmp = stack->list_a;
	next_min = 0;
	if (tmp->value == stack->min)
	{
		next_min = tmp->next->value;
		tmp = tmp->next;
	}
	else
		next_min = tmp->value;
	while (tmp)
	{
		if (tmp->value != stack->min)
		{
			if (tmp->value < next_min)
				next_min = tmp->value;
			tmp = tmp->next;
		}
		else
			tmp = tmp->next;
	}
	return (next_min);
}

void	get_min(t_utils *stack)
{
	t_node	*tmp;

	tmp = stack->list_a;
	stack->min = tmp->value;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->value < stack->min)
			stack->min = tmp->value;
	}
}

void	get_max(t_utils *stack)
{
	t_node	*tmp;

	tmp = stack->list_a;
	stack->max = tmp->value;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->value > stack->max)
			stack->max = tmp->value;
	}
}

void	get_max_b(t_utils *stack)
{
	t_node	*tmp;

	tmp = stack->list_b;
	stack->max_b = tmp->value;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->value > stack->max_b)
			stack->max_b = tmp->value;
	}
}

int	get_distance(t_utils *stack)
{
	t_node	*tmp;
	int		pos;

	tmp = stack->list_a;
	pos = 1;
	while (tmp)
	{
		if (tmp->value == stack->min)
			break ;
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}
