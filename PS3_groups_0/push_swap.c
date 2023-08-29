/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:33:08 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 10:33:08 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	all(t_utils *stack, int num)
{
	int	pos;

	while (ft_lstsize(stack->listA) > ((stack->max + 1) - (num * stack->third)))
	{
		pos = verification_a(stack, num);
		if (stack->listA->value < (num * stack->third))
		{
			pb(stack);
			verification_b(stack, num);
		}
		else
		{
			if (pos == 1)
				while (stack->listA->value >= (num * stack->third))
					ra(stack);
			else
				while (stack->listA->value >= (num * stack->third))
					rra(stack);
		}
	}
}

void	last(t_utils *stack, int num)
{
	while (ft_lstsize(stack->listA) > 3)
	{
		if (stack->listA->value <= (stack->max - 3))
		{
			pb(stack);
			verification_b(stack, num);
		}
		else
			ra(stack);
	}
	if (ft_lstsize(stack->listA) < 3 && !is_sorted(stack->listA))
	{
		sa(stack);
	}
	else if (ft_lstsize(stack->listA) == 3 && !is_sorted(stack->listA))
		sort_3(stack);
}

int	index_max_b(t_utils *stack)
{
	t_node	*tmp;
	int		i;

	tmp = stack->listB;
	i = 1;
	while (tmp->value != stack->max_b)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	move_to_a(t_utils *stack)
{
	int	pos;

	pos = 0;
	while (ft_lstsize(stack->listB) || 
		(!is_sorted(stack->listA) && !is_sorted(stack->listB)))
	{
		get_max_b(stack);
		pos = index_max_b(stack);
		if (pos > (ft_lstsize(stack->listB) / 2))
		{
			while (stack->listB->value != stack->max_b)
				rrb(stack);
			pa(stack);
		}
		else
		{
			while (stack->listB->value != stack->max_b)
				rb(stack);
			pa(stack);
		}
	}
	while (ft_lstsize(stack->listB))
		pa(stack);
}

void	ft_alg2(t_utils *stack)
{
	int	num;
	int	i;

	num = 0;
	if (stack->max > 200 || stack->max <= 9)
		num = 11;
	else
		num = 3;
	stack->third = (stack->max + 1) / num;
	i = 1;
	while (i < num)
	{
		all(stack, i);
		i++;
	}
	last(stack, num);
	move_to_a(stack);
}
