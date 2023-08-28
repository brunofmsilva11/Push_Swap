/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:07:42 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 17:17:29 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao indica-me o tamanho da lista ou seja o numero de nodes. */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t	i;

	i = 0;
	if (lst == NULL)
		return (0);
	while (lst != NULL)
	{
		lst = lst -> next;
		i++;
	}
	return (i);
}

/* #include <stdio.h>
int main()
{
  char    str[] = "Bruno";
  char    str2[] = "24";
  t_list    *elem, *elem2;
  t_list *head;
  size_t i;
  elem = ft_lstnew((void *)str);
  elem2 = ft_lstnew((void *)str2);
  head = elem;
  elem -> next = elem2;
  elem2 -> next = NULL;
  i = ft_lstsize (head);
  printf("%d\n", i);
} */