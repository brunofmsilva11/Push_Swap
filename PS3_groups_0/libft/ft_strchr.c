/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:00:34 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 13:39:20 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Esta funcao recebe uma string e um caracter e 
verifica se esse caracter existe na
string e imprime a partir dele. 
*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s + i);
}

/*#include <stdio.h>
int main () {
   const char str[] = "42 Cursus\nPortojhhaskjfhajk\nkasjfo";
   const char ch = '\n';
   char *ret;

   ret = ft_strchr(str, ch) + 1;

   printf("String after |%c| is - |%s|\n", ch, ret);
   
   return(0);
}*/