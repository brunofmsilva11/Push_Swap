/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:31:18 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/28 14:55:30 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao cria um novo no. */

#include "libft.h"

t_node	*ft_lstnew(int content)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = content;
	new_node->next = NULL;
	return (new_node);
}

/* #include <stdio.h>

int main()
{
    char str[] = "42 Porto.";
    char id[] = "1 ano"; 
    t_node *novo_no;
    t_node *idade;
    t_node *head;

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