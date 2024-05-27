/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:58:55 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/30 11:49:36 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_utils
{
	t_node	*list_a;
	t_node	*list_b;
	int		*array;
	int		max_bits;
	int		max;
	int		min;
	int		max_b;
	int		third;
}				t_utils;

/*array.c*/
void	swap2(int *a, int *b);
void	ordenar(int *array, t_utils *stack);
void	ft_index(int *array, t_utils *stack);
void	index3(t_utils *stack);

//check.c
void	check_list(char **av, int ac);
void	check_signals(char **av, int len);
void	check_if_numbers(char **av, int len);
void	check_doubles(char **av, int len);

//free.c
void	free_list(t_utils *stack);

//get.c
int		get_next_min(t_utils *stack);
void	get_min(t_utils *stack);
void	get_max(t_utils *stack);
void	get_max_b(t_utils *stack);
int		get_distance(t_utils *stack);

//main.c
void	put_prev(t_node *list);
void	create_list(t_utils *stack, char **av);
int		main(int ac, char **av);

//push_swap.c
void	all(t_utils *stack, int num);
void	last(t_utils *stack, int num);
int		index_max_b(t_utils *stack);
void	move_to_a(t_utils *stack);
void	ft_alg2(t_utils *stack);

//simple_sort
void	sort_3(t_utils *stack);
void	sort_4(t_utils *stack);
void	sort_5(t_utils *stack);
void	simple(t_utils *stack);

//utils.c
void	init_stack(t_utils *stack);
int		is_sorted(t_node *list);

//verification.c
int		verification_a(t_utils *stack, int num);
void	verification_b(t_utils *stack, int num);

//commands/push.c
void	push(t_node **stack_to, t_node **stack_from);
void	pa(t_utils *stack);
void	pb(t_utils *stack);

//commands/reverserotate.c
void	reverse_rotate(t_node **stack);
void	rra(t_utils *stack);
void	rrb(t_utils *stack);
void	rrr(t_utils *stack);
void	remove_node(t_node **t_node, int num);

//commands/rotate.c
void	rotate(t_node **stack);
void	ra(t_utils *stack);
void	rb(t_utils *stack);
void	rr(t_utils *stack);

//commands/swap
void	swap(t_node *t_node);
void	sa(t_utils *stack);
void	sb(t_utils *stack);
void	ss(t_utils *stack);

#endif