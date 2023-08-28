/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:00:10 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 17:21:19 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao recebe uma string e um caracter e 
imprime a partir desse caracter.
Se nao encontrar o caracter na string retorna NULL. */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	character;

	str = (unsigned char *)s;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == character)
		{
			return (str);
		}
		str++;
		i++;
	}
	return (NULL);
}

/* int main () {
   const char str[] = "http://www.tutorialspoint.com";
   const char ch = 'o';
   char *ret;

   ret = memchr(str, ch, 15);

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
} */
