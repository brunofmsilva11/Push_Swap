/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:22:33 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/22 16:45:29 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Recebe um inteiro e tranforma em string.
Primeiro ele ve quantos algarismos tem o numero com o int_len.
Cria uma string que recebe a quantidade de memoria necessaria 
para a string receber o intero (malloc).
Colocar o numero index na variavel = '\0'.
Se for positivo insere na string o numero de tras para a frente.
Se for negativo considera o primeiro index da string = '-', 
multiplica o numero por -1 e depois faz o mesmo como se fosse 
positivo. */

static char	*posnum(char *str, int n, int len)
{
	long	x;

	len--;
	x = n;
	while (len >= 0)
	{
		str[len] = x % 10 + '0';
		x = x / 10;
		len--;
	}
	return (str);
}

static char	*negnum(char *str, int n, int len)
{
	long	x;

	x = n;
	str[0] = '-';
	len--;
	x = x * (-1);
	while (len > 0)
	{
		str[len] = (x % 10) + '0';
		x = x / 10;
		len--;
	}
	return (str);
}

static int	int_len(int n)
{
	int		i;
	long	x;

	x = n;
	i = 0;
	if (x <= 0)
	{
		x = x *(-1);
		i++;
	}
	while (x > 0)
	{
		x = x / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = int_len(n);
	str = (char *) malloc (sizeof (char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str = negnum(str, n, len);
	}
	else if (n == 0)
		str[0] = '0';
	else
		str = posnum(str, n, len);
	return (str);
}

/* #include <stdio.h>
int main()
{
	char *b;
	b = ft_itoa(-2147483648);
	printf("%s\n", b);
	return 0;
} */