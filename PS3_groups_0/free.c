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

	while (stack->listA != NULL)
	{
		temp = stack->listA;
		stack->listA = stack->listA->next;
		free (temp);
	}
	free (stack->listA);
	while (stack->listB != NULL)
	{
		temp = stack->listB;
		stack->listB = stack->listB->next;
		free (temp);
	}
	free (stack->listB);
}
