/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:57:56 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/28 14:43:27 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao adiciona um novo no ao inicio da lista
o novo no aponta para o conteudo de lst e o conteudo de lst vai ser
o enderenco do new.
*/

#include "libft.h"

void	ft_lstadd_front(t_node **lst, t_node *new)
{
	if (new != NULL)
	{
		new -> next = *lst;
		*lst = new;
	}
}
