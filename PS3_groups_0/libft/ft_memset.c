/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:00:30 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 17:20:31 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Esta funcao altera na string o numero de caracteres n pelo caracter c.
*/

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = c;
		i++;
	}
	return (str);
}

/* int main () {
   char str[] = "This is string.h library function";

   ft_memset(str,'$',7);

   printf("%s\n", str);
   return(0);
} */