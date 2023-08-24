/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:58:55 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/24 15:48:55 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_node{
    int value;
    struct s_node *prev;
    struct s_node *next;
}t_node;

typedef struct s_utils
{
	t_node *listA;
	t_node *listB;
	int max_bits;
	int max;
	int min;
	int max_b;
	int third;
}t_utils;

//new2.c
int    	verification(t_utils *stack);
void    ft_sort_b(t_utils *stack, int shift);
void    verification_b(t_utils *stack, int num);
void    all(t_utils *stack, int num);
void    first(t_utils *stack);
void    second(t_utils *stack);
void    last(t_utils *stack);
//int     index_a(t_utils *stack);
int     index_max_b(t_utils *stack);
//void    move_to_b(t_utils *stack);
void    move_to_a(t_utils *stack);
void    ft_alg2(t_utils *stack);
void    ft_index(int *array, t_utils *stack);
void    index3(t_utils *stack);
int 	main(int ac, char **av);

//insert.c
void    insert_top(t_node **lista, int num);
void    insert_end(t_node **lista, int num);
void    insert_mid(t_node **lista, int num, int pre);

//print.c
void imprimirA(t_node *t_node);
void imprimirB(t_node *t_node);

//commands/push.c
void    push(t_node **list_to, t_node **list_from);
void    pa(t_utils *stack);
void    pb(t_utils *stack);

//commands/reverserotate.c
void    reverse_rotate(t_node **t_node);
void    rra(t_utils *stack);
void    rrb(t_utils *stack);
void    rrr(t_utils *stack);
void    remove_node(t_node **t_node, int num);

//commands/rotate.c
void    rotate(t_node *t_node);
void    ra(t_utils *stack);
void    rb(t_utils *stack);
void    rr(t_utils *stack);

//commands/swap
void    swap(t_node *t_node);
void    sa(t_utils *stack);
void    sb(t_utils *stack);
void    ss(t_utils *stack);

//simple_sort
int         is_sorted(t_node *list);
int 		sorted_is(t_node *list);
void        sort_3(t_utils *stack);
void        sort_4(t_utils *stack);
void        sort_5(t_utils *stack);
void        simple(t_utils *stack);

//get.c
int  	get_next_min(t_utils *stack);
void  	get_min(t_utils *stack);
void  	get_max(t_utils *stack);
void    get_max_b(t_utils *stack);
int    	get_distance(t_utils *stack);

//lstsize.c
int    lstsize(t_node *t_node);

//sort.c
t_utils	*setup_utils(t_node **listA, t_node **listB);
void	check_best_min_max(t_node *t_node_a, t_node *t_node_b, t_utils *utils);
void	check_best_default_2(t_utils *utils, int mov, int i, t_node *t_node_a);
void	check_best_default(t_node *t_node_a, t_node *t_node_b, t_utils *utils);
void	check_best_move_2(t_node **listA, t_node **listB, t_utils *utils);
void	check_best_move(t_node **listA, t_node **listB);
void	sort_end(t_node **listA);
void	sort_big(t_node **listA, t_node **listB);

//prepare_push.c
void	rotate_min_max(t_node **listB, t_utils *utils);
void	rotate_default(t_node **listA, t_node **listB, t_utils *utils);
void	prepare_to_push_2(t_node **listA, t_utils *utils, int i);
void	prepare_to_push(t_node **listA, t_node **listB, t_utils *utils);

/*array.c*/
void    swap2(int *a, int *b);
void    ordenar(int *array, t_utils *stack);
void    print_array(int *array);

//utils.c
void    init_stack(t_utils *stack);

#endif