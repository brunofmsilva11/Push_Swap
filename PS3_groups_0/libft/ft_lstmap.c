/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:26:17 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 17:19:41 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao com a lista feita aplicas a funcao f em 
cada no e podes ou nao utilizar a funcao del.
ao aplicar a funcao criamos um novo no com o f aplicado 
criando assim uma nova lista. */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void*))
{
	t_list	*temp;
	t_list	*new;
	int		size;

	(void)del;
	size = ft_lstsize(lst);
	if (size == 0)
		return (0);
	temp = ft_lstnew(f(lst->content));
	if (!temp)
		return (0);
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&temp, del);
			return (0);
		}	
		ft_lstadd_back(&temp, new);
		lst = lst->next;
	}
	return (temp);
}
