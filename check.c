/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 11:39:34 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/30 11:47:00 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_list(char **av, int ac)
{
	check_if_numbers(av, ac);
	check_doubles(av, ac);
	check_signals(av, ac);
}

void	check_signals(char **av, int len)
{
	int	i;
	int	j;
	int	num_sig;

	i = 1;
	j = 0;
	num_sig = 0;
	while (i < len)
	{
		j = 0;
		num_sig = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' || av[i][j] == '+')
				num_sig++;
			if (num_sig > 1)
			{
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
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
