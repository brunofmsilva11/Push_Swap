/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:00:52 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 17:20:44 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao recebe 2 strings e compara uma com a outra durante n caracteres.
Verifica se sao iguais, se forem diferentes retorna a difernca entre eles. */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
	i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* int main(void) {
	char str1[] = "Bruno"; 
	char str2[] = "Brruno";
	int i = 2;
	printf("Result: %d\n", ft_strncmp(str1, str2, i));
} */