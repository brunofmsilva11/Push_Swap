/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:26:58 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/28 00:57:25 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_stack(t_utils *stack)
{
    stack->listA = NULL;
    stack->listB = NULL;
    stack->max_bits = 0;
    stack->max = 0;
    stack->min = 0;
    stack->max_b = 0;
    stack->third = 0;
}

int	check_if_numbers(char **av, int len)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < len)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] >= '0' && av[i][j] <= '9') ||
				av[i][j] == '-' || av[i][j] == '+')
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_doubles(t_node *list)
{
	t_node *aux = list;
    while(aux)
    {
        t_node *aux2 = aux->next;
        while(aux2)
        {
            if(aux->value == aux2->value)
                return (0);
            aux2 = aux2->next;
        }
        aux = aux->next;
    }
    return (1);
}