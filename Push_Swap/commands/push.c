/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:03:44 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 16:29:35 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//PUSH
void	push(t_node **stack_to, t_node **stack_from)
{
	t_node	*tmp;
	t_node	*head_to;
	t_node	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return ;
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
}

void	pa(t_utils *stack)
{
	push(&stack->list_a, &stack->list_b);
	write(1, "pa\n", 3);
}

void	pb(t_utils *stack)
{
	push(&stack->list_b, &stack->list_a);
	write(1, "pb\n", 3);
}
