/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 11:34:33 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/16 15:19:52 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_utils	*setup_utils(Node **listA, Node **listB)
{
	t_utils	*utils;

	utils = malloc (sizeof(t_utils));
	utils->len_b = lstsize(*listB);
	utils->len_a = lstsize(*listA);
	utils->max = get_max(listB);
	utils->min = get_min(listB);
	utils->curr_moves = 0;
	utils->nb_index_a = 0;
	utils->nb_index_b = 0;
	utils->best_moves = 0;
	utils->nb = 0;
	/* utils->ra = 0;
	utils->rb = 0;
	utils->rra = 0;
	utils->rrb = 0; */
	return (utils);
}

void	check_best_min_max(Node *node_a, Node *node_b, t_utils *utils)
{
	int	mov;
	int	i;

	i = 1;
	while (node_b->value != utils->max)//Percorre a lista B ate ao max e conta os movimentos
	{
		i++;
		node_b = node_b->next;
	}
	mov = i;
	if (mov > (utils->len_b / 2))//Verifica se o max esta na segunda parte da lista B
		mov = utils->len_b - mov;//se estiver vamos contar os movimentos apartir do fim da lista B
	mov = mov + utils->curr_moves;//somamos os movimentos para achar o maximo + os movimentos atuais
	if (!utils->best_moves || mov < utils->best_moves)//Se os best_moves for Null ou os movimentos contados agora forem menores que o best_moves
	{
		utils->nb_index_b = i;//guardamos a posicao do maximo da lista B
		utils->best_moves = mov;//os movimentos ficam como melhores movimentos
		utils->nb = node_a->value;//guardamos o valor da lista A,
	}
}

void	check_best_default_2(t_utils *utils, int mov, int i, Node *node_a)
{
	if (!(utils->best_moves) || mov < utils->best_moves)
	{
		utils->nb_index_b = i;
		utils->best_moves = mov;
		utils->nb = node_a->value;
	}
}

void	check_best_default(Node *node_a, Node *node_b, t_utils *utils)
{
	int	mov;
	int	i;
	int	curr_b_rev;

	i = 1;
	curr_b_rev = 0;
	while (!(node_a->value < node_b->value && node_a->value > node_b->next->value))
	{
		i++;
		node_b = node_b->next;
	}
	mov = i;
	if (mov > (utils->len_b / 2))
	{
		mov = utils->len_b - mov;
		curr_b_rev = 1;
	}
	if (curr_b_rev == utils->curr_a_rev)
	{
		if (utils->curr_moves > mov)
			mov = utils->curr_moves;
	}
	else
		mov = mov + utils->curr_moves;
	check_best_default_2(utils, mov, i, node_a);
}


void	check_best_move_2(Node **listA, Node **listB, t_utils *utils)
{
	int		i;
	Node	*node_a;
	Node	*node_b;

	i = -1;
	node_a = (*listA);
	while (++i <= (utils->len_a))//este while vai percorrer a lista A.
	{
		node_b = (*listB);
		if (node_a->value < utils->max && node_a->value > utils->min)//verifica se o valor da lista A esta entre i min e o max de B
			check_best_default(node_a, node_b, utils);
		else
			check_best_min_max(node_a, node_b, utils);//Descobrir a posicao do maximo da lista B e o melhores movimentos possiveis para encontra lo
		utils->curr_moves++;
		if (i == (utils->len_a / 2))//Como passou a metade da listaA enviamos o node_a para o ultimo valor da lista para verificar cumpre os parametros
		{
			utils->curr_a_rev = 1;
			utils->curr_moves = 1;//comeca a contar do 1 pois vai para o fim da lista para encontrar a partir da outra metade
			node_a = (*listA)->prev;//Envia para o ultimo valor da listA
		}
		else if (i < (utils->len_a / 2))//Verifica se o i esta na primeira metade da lista
			node_a = node_a->next;//se estiver passamos para o proximo node
		else
			node_a = node_a->prev;//se estiver na segunda parte da lista passamos para o node anterior
	}
}

void	check_best_move(Node **listA, Node **listB)
{
	t_utils	*utils;

	utils = setup_utils(listA, listB);
	utils->curr_a_rev = 0;
	check_best_move_2(listA, listB, utils);
	prepare_to_push(listA, listB, utils);
	//free(utils);
}

void	sort_end(Node **listA)
{
	int		min;
	int		i;
	int		len;
	Node	*node;

	i = 0;
	min = get_min(listA);
	node = (*listA);
	len = lstsize(*listA);
	while (node->value != min)
	{
		node = node->next;
		i++;
	}
	if (i <= (len / 2))
		while ((*listA)->value != min)
			ra(listA);
	else
		while ((*listA)->value != min)
			rra(listA);
}

void	sort_big(Node **listA, Node **listB)
{
	pb(listB, listA);
	pb(listB, listA);
	if ((*listB)->value < (*listB)->next->value)
		sb(listB);
	while (lstsize(*listA) != 0)
		check_best_move(listA, listB);
	while (lstsize(*listB) != 0)
		pa(listA, listB);
	sort_end(listA);
}