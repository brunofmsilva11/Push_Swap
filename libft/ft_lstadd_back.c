/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:29:00 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 13:51:32 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao adiciona um no ao fim da lista ou 
seja este no adicionado o next dele tem de ser NULL. */

#include "libft.h"

void	ft_lstadd_back(t_node **lst, t_node *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	if (new == NULL)
		return ;
	ft_lstlast(*lst)->next = new;
	new->next = NULL;
}
