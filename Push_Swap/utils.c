/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:26:58 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 17:12:05 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_utils *stack)
{
	stack->list_a = NULL;
	stack->list_b = NULL;
	stack->max_bits = 0;
	stack->max = 0;
	stack->min = 0;
	stack->max_b = 0;
	stack->third = 0;
}

void	check_list(char **av, int ac)
{
	check_doubles(av, ac);
	check_if_numbers(av, ac);
}

int	is_sorted(t_node *list)
{
	t_node	*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	check_if_numbers(char **av, int len)
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
			{
				ft_printf("Error\n");
				exit(1);
			}
		}
		i++;
	}
}

void	check_doubles(char **av, int len)
{
	int		i;
	int		j;
	long	num;
	long	num2;

	i = 1;
	while (i < len)
	{
		j = 1;
		while (j < i)
		{
			num = ft_atol(av[i]);
			num2 = ft_atol(av[j]);
			if (num == num2 || num < INT_MIN || num > INT_MAX)
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}
