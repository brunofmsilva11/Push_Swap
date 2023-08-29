/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:27:42 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 16:27:52 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap2(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ordenar(int *array, t_utils *stack)
{
	int	j;

	j = 0;
	while (j < ft_lstsize(stack->list_a) - 1)
	{
		if ((array[j] > array[j + 1]) && (j - 1 < ft_lstsize(stack->list_a)))
		{
			swap2(&array[j], &array[j + 1]);
			j = 0;
		}
		else
			j++;
	}
}

void	ft_index(int *array, t_utils *stack)
{
	t_node	*aux;
	int		i;

	aux = stack->list_a;
	while (aux)
	{
		i = 0;
		while (array)
		{
			if (aux->value == array[i])
			{
				aux->value = i;
				break ;
			}
			i++;
		}
		aux = aux->next;
	}
}

void	index3(t_utils *stack)
{
	t_node	*aux;
	int		*array;
	int		i;

	aux = stack->list_a;
	array = malloc(sizeof(int) * (ft_lstsize(stack->list_a)));
	i = 0;
	while (aux)
	{
		array[i] = aux->value;
		aux = aux->next;
		i++;
	}
	ordenar(array, stack);
	ft_index(array, stack);
	get_min(stack);
	get_max(stack);
	ft_alg2(stack);
	free(array);
}
