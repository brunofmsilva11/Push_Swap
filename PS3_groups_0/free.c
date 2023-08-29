/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:43:19 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 10:43:19 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_utils *stack)
{
	t_node	*temp;

	while (stack->list_a != NULL)
	{
		temp = stack->list_a;
		stack->list_a = stack->list_a->next;
		free (temp);
	}
	free (stack->list_a);
	while (stack->list_b != NULL)
	{
		temp = stack->list_b;
		stack->list_b = stack->list_b->next;
		free (temp);
	}
	free (stack->list_b);
}
