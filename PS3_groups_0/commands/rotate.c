/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:02:58 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/28 23:38:10 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//ROTATE
void	rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	if (ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
}

void	ra(t_utils *stack)
{
	rotate(&stack->listA);
	write(1, "ra\n", 3);
}

void	rb(t_utils *stack)
{
	rotate(&stack->listB);
	write(1, "rb\n", 3);
}

void	rr(t_utils *stack)
{
	rotate(&stack->listA);
	rotate(&stack->listB);
	write(1, "rr\n", 3);
}
