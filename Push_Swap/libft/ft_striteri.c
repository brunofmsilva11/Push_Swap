/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:18:43 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 16:31:13 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
esta funcao recebe uma string e um pointer para uma funcao.
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

/* void my_func(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
	{
		*c -= 32;
	}
}

int main()
{
	char str[] = "hello.";
	ft_striteri(str, &my_func);
	printf("%s", str);
	return (0);
} */