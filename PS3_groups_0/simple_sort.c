/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 12:54:52 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 11:42:02 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_utils *stack)
{
	t_node	*tmp;
	int		next_min;

	tmp = stack->listA;
	get_min(stack);
	next_min = get_next_min(stack);
	if (tmp->value == next_min && tmp->next->value == stack->min)
		sa(stack);
	else if (tmp->value != stack->min && tmp->value != next_min)
	{
		if (tmp->next->value == next_min)
		{
			sa(stack);
			rra(stack);
		}
		else
			ra(stack);
	}
	else if (tmp->value == stack->min && tmp->next->value != next_min)
	{
		sa(stack);
		ra(stack);
	}
	else
		rra(stack);
}

void	sort_4(t_utils *stack)
{
	int	distance;

	if (is_sorted(stack->listA))
		return ;
	get_min(stack);
	distance = get_distance(stack);
	if (distance == 2)
		ra(stack);
	else if (distance == 3)
	{
		ra(stack);
		ra(stack);
	}
	else if (distance == 4)
	{
		rra(stack);
	}
	if (is_sorted(stack->listA))
		return ;
	pb(stack);
	sort_3(stack);
	pa(stack);
}

void	sort_5(t_utils *stack)
{
	int	distance;

	get_min(stack);
	distance = get_distance(stack);
	if (distance == 2)
		ra(stack);
	else if (distance == 3)
	{
		ra(stack);
		ra(stack);
	}
	else if (distance == 4)
	{
		rra(stack);
		rra(stack);
	}
	else if (distance == 5)
		rra(stack);
	if (is_sorted(stack->listA))
		return ;
	pb(stack);
	sort_4(stack);
	pa(stack);
}

void	simple(t_utils *stack)
{
	int	size;

	size = ft_lstsize(stack->listA);
	if (is_sorted(stack->listA) || size < 2)
		return ;
	if (size == 2)
		sa(stack);
	else if (size == 3)
		sort_3(stack);
	else if (size == 4)
		sort_4(stack);
	else if (size == 5)
		sort_5(stack);
}
