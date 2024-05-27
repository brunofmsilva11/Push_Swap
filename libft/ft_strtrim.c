/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:40:52 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 17:24:17 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao recebe 2 strings uma com a condicao
 que se existir no inicio e no fim da outra remove. */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*res;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1))
	{
		s1++;
	}
	i = ft_strlen(s1) - 1;
	while (i && ft_strchr(set, s1[i]))
	{
		i--;
	}
	res = ft_substr(s1, 0, i + 1);
	return (res);
}

/* #include <stdio.h>
int main()
{
    char a[] = "  oobc odef oo  ";
    char s[] = " o";
    char *str;

    str = ft_strtrim(a, s);
    printf("|%s|\n", str);

    return 0;
} */