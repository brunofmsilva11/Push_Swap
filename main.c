/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 12:09:30 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/30 12:09:30 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_prev(t_node *list)
{
	t_node	*tmp;

	tmp = list;
	while (tmp->next)
	{
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	list->prev = tmp;
}

void	create_list(t_utils *stack, char **av)
{
	t_node	*new_node;
	t_node	*tmp;
	int		value;
	int		i;

	i = 1;
	while (av[i] != NULL)
	{
		value = ft_atol(av[i]);
		new_node = ft_lstnew(value);
		ft_lstadd_back(&stack->list_a, new_node);
		i++;
	}
	tmp = stack->list_a;
	while (tmp->next)
	{
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	stack->list_a->prev = tmp;
}

int	main(int ac, char **av)
{
	t_utils	*stack;

	if (ac < 2)
		exit(1);
	check_list(av, ac);
	stack = malloc(sizeof(t_utils));
	init_stack(stack);
	create_list(stack, av);
	if (is_sorted(stack->list_a))
	{
		free_list(stack);
	}
	else if (ft_lstsize(stack->list_a) > 5)
		index3(stack);
	else
		simple(stack);
	free_list(stack);
	free(stack);
	return (1);
}
