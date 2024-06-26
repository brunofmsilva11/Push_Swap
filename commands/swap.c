/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 12:02:32 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 16:29:42 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node *node)
{
	int	tmp;

	tmp = node->value;
	node->value = node->next->value;
	node->next->value = tmp;
}

void	sa(t_utils *stack)
{
	swap(stack->list_a);
	write(1, "sa\n", 3);
}

void	sb(t_utils *stack)
{
	swap(stack->list_b);
	write(1, "sb\n", 3);
}

void	ss(t_utils *stack)
{
	swap(stack->list_a);
	swap(stack->list_b);
	write(1, "ss\n", 3);
}
