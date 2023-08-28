/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:31:18 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/27 22:35:48 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao cria um novo no. */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/* #include <stdio.h>

int main()
{
    char str[] = "42 Porto.";
    char id[] = "1 ano"; 
    t_list *novo_no;
    t_list *idade;
    t_list *head;

    novo_no = ft_lstnew((void *)str);
    idade = ft_lstnew((void *)id);
    head = novo_no;
    novo_no->next = idade;
    idade->next = NULL;

    printf("\n%s\n", head->content);
    printf("%s\n", *novo_no-> next);
    printf("\n%s\n", (char *)idade->content);
    printf("\n%s\n", (char *)idade->next);
    return 0;
} */