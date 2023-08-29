/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:03:27 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/28 23:37:02 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//REVERSEROTATE
void	reverse_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*tail;

	if (ft_lstsize(*stack) < 2)
		return ;
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
}

void	rra(t_utils *stack)
{
	reverse_rotate(&stack->listA);
	write(1, "rra\n", 4);
}

void	rrb(t_utils *stack)
{
	reverse_rotate(&stack->listB);
	write(1, "rrb\n", 4);
}

void	rrr(t_utils *stack)
{
	reverse_rotate(&stack->listA);
	reverse_rotate(&stack->listB);
	write(1, "rrr\n", 4);
}

void	remove_node(t_node **node, int num)
{
	t_node	*aux;
	t_node	*remove;

	aux = NULL;
	remove = NULL;
	aux = *node;
	while ((aux->next != NULL) && (aux->next->value != num))
		aux = aux->next;
	if (aux->next)
	{
		remove = aux->next;
		aux->next = remove->next;
	}
}
