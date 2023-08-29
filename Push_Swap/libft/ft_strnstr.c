/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:00:56 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 17:19:14 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao recebe 2 strings e compara uma com a 
outra se verificar que a string(little)
existe na string(big) retorna a string a partir desse ponto. */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little [0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && little[j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (0);
}

/* int main () 
{
 const char haystack[20] = "TutorialsPoint";
 const char needle[10] = "al";
 char *result;

 result = ft_strnstr(haystack, needle, 4);
 printf("The substring is: %s\n", result);
 return(0);
} */