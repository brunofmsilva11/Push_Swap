/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:59:12 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 17:21:01 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
       A funcao bzero tranforma o valor recebido *s em 0, ou seja,
	   recebe o 'B' = 66 e coloca igual a '\0' = 0. Neste caso como metemos str + 2
	   vai comecar a verificar a partir da 2 posicao da string. 
*/
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*string;

	string = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		string[i] = 0;
		i++;
	}
}

/* #include <stdio.h>
int main()
{
	
	char str[] = "Bruno";
	
	ft_bzero(str + 2, 1);
	
	printf("%s\n", str);
	return (0);
} */