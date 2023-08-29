/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:07:33 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 13:44:30 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Esta funcao retorna a string a partir de um index ate ao len.
*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	a;

	a = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = (char *)malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[a] = 0;
		return (str);
	}
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (a < len)
	{
		str[a] = s[start + a];
		a++;
	}
	str[a] = '\0';
	return (str);
}

/* #include <stdio.h>

int main()
{
  char c[] = "183-55-4899-1368-445";
  char *str;
  str = ft_substr(c, 7, 4);
  printf("%s\n", str);
  return 0;
} */