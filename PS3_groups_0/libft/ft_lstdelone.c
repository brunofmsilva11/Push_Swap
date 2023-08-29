/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:24:14 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 13:44:05 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao apaga um no. t_node *node_to_delete = ...; 
Preencha este valor com o nó que você deseja apagar
ft_lstdelone(node_to_delete); nao esquecer depois de apagar 
apontar a lista para o valor_apagado->next*/

#include "libft.h"

void	ft_lstdelone(t_node *node)
{
	if (node != NULL)
	{
		free(node);
	}
}
