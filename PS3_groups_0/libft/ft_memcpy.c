/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:00:21 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 15:48:31 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao aceita dois pointers para uma string e 
coloca o valor de index[0] de uma na outra de valor index[0].
Copia a memoria alocada de uma string para outra, podendo haver sobreposicao
como no exemplo. 
 */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*pt_det;
	unsigned char		*pt_src;
	size_t				i;

	pt_det = (unsigned char *)dest;
	pt_src = (unsigned char *) src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		pt_det[i] = pt_src[i];
		i++;
	}
	return (pt_det);
}

/* 
int main (void) 
{
  char src[] = "hello world";
	ft_memcpy(src + 3, src, 5);
  printf("After memcpy dest = %s\n", src);
   
  return(0);
} */