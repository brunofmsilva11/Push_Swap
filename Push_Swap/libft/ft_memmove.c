/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:00:26 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 17:22:46 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
A funcao recebe 2 pointers para 2 arrays e 1 valor n, ou seja,
move n caracteres de src para dest.
Verifica se a memoria dos pointers nao esta subreposta, se estiver
move os caracteres de um array para o outro de tras para a frente.
Esta funcao e indentica a memcpy mas quando ha sobreposicao da memoria
a funcao imprime de tras para a frente
 (para nao perder a caracteres da string) */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*p_src;
	unsigned char	*p_dest;

	p_src = (unsigned char *)src;
	p_dest = (unsigned char *)dest;
	if (!dest && !src)
		return (NULL);
	if (dest > src && dest - src < (int)n)
	{
		while (n != 0)
		{
			n--;
			p_dest[n] = p_src[n];
		}
		return (dest);
	}
	ft_memcpy(dest, src, n);
	return (dest);
}

/* #include <stdio.h>
int main()
{
	char dest[] = "42 Portodskvnkjnvskjnb";
	char src[] = "hello world";
	ft_memmove(dest, src, 30);
	printf("After memcpy dest = %s\n", dest);
}
 */