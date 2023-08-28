/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:01:01 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 19:28:17 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Esta funcao recebe uma string e um caracter e encontra a 
ultima vez que o caracter estava na string.
a funcao comeca a ver a string de tras para a frente.
*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	pos;

	pos = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + pos));
	while (pos >= 0)
	{
		if (s[pos] == c)
			return ((char *)(s + pos));
		pos--;
	}
	return (NULL);
}

/* #include <stdio.h>
int	main()
{
	char *str = "aacaaacaaaaaaaa";
	char c = 'c';
	char *a = ft_strrchr(str, c);
	printf("%c\n", *a);
	return 0;
} */