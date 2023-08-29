/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:34:16 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 13:46:13 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao apaga a lista toda de no em no. 
E criado um aux para nao perder a referencia do valor a seguir.*/

#include "libft.h"

void	ft_lstclear(t_node **lst)
{
	t_node	*aux;

	if (lst == NULL)
		return ;
	aux = *lst;
	while (aux)
	{
		aux = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = aux;
	}
}
