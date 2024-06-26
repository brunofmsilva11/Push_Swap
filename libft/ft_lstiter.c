/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:54:48 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/28 15:05:00 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao aplica uma funcao no conteudo de cada no. */

#include "libft.h"

void	ft_lstiter(t_node *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->value);
		lst = lst->next;
	}
}
