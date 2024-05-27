/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:00:41 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 17:19:18 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao recebe 2 strings e um size, junta as duas 
strings e retorna o tamanho da string gerada
independentemente do size. */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (dst == NULL && size == 0)
		return (0);
	while (dst[i] && i < size)
		i++;
	while (src[j] && (i + j + 1) < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/* #include <stdio.h>
int main (void)
{
char src[] = "Silva";
char dest [] = "Bruno";
printf("%d \n", ft_strlcat(dest, src, 7)); nr de caracteres total 
											ao juntar src +dest
se quiser ver a string completa na totalidade nao esquecer o '\0' ou seja
total + 1 
printf("%s \n", dest); //string junta
return 0;
}  */