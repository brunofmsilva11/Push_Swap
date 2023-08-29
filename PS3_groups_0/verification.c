/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 10:37:18 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 10:37:18 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verification_a(t_utils *stack, int num)
{
	t_node	*tmp;
	t_node	*aux;
	int		i;
	int		k;

	aux = stack->list_a;
	tmp = stack->list_a;
	put_prev(aux);
	k = 1;
	i = 1;
	while (tmp->value >= (num * stack->third))
	{
		i++;
		tmp = tmp->next;
	}
	while (aux->value >= (num * stack->third))
	{
		k++;
		aux = aux->prev;
	}
	if (i > k)
		return (-1);
	else
		return (1);
}

void	verification_b(t_utils *stack, int num)
{
	if (ft_lstsize(stack->list_b) > 1)
	{
		if (stack->list_b->value <= ((stack->third * num) - (stack->third / 2)))
			rb(stack);
	}
}
