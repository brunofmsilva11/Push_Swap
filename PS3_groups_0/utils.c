/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:26:58 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 16:31:54 by bmota-si         ###   ########.fr       */
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
	check_doubles(av);
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

int	check_doubles(char **av)
{
	int		i;
	long	num;
	long	num2;

	i = 1;
	while (av[i + 1])
	{
		num = ft_atol(av[i]);
		num2 = ft_atol(av[i + 1]);
		if (num == num2 || num > INT_MAX || num < INT_MIN)
		{
			ft_printf("Error\n");
			exit(1);
		}
		i++;
	}
	return (1);
}
