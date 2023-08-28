/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:00:18 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 17:28:57 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Esta funcao recebe uma string e um caracter e verifica 
se esse caracter existe 
na string e ignora. */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	int	word;
	int	count;

	count = 0;
	word = 0;
	while (*s != '\0')
	{
		if (*s != c && count == 0)
		{
			word++;
			count = 1;
		}
		else if (*s == c)
		{
			count = 0;
		}
		s++;
	}
	return (word);
}

static int	letter_index(const char *s, char c, int a)
{
	int	len;

	len = 0;
	while (s[a] != c && s[a] != '\0')
	{
		a++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	word;
	size_t	a;
	size_t	b;
	char	**str;

	a = 0;
	b = 0;
	if (!s)
		return (NULL);
	word = word_count(s, c);
	str = (char **)malloc(sizeof(char *) * (word + 1));
	if (str == NULL)
		return (NULL);
	while (b < word)
	{
		while (s[a] == c)
			a++;
		str[b] = ft_substr(s, a, (letter_index(s, c, a)));
		if (!str)
			return (NULL);
		a += letter_index(s, c, a);
		b++;
	}
	str[b] = 0;
	return (str);
}

/*#include <stdio.h>
int	main()
{
   char    str[] = "b sm d";
   char **splited;
   int     a;
   a = 0;
   splited = ft_split(str, ' ');
   while (splited[a])
   {
      printf ("%s", splited[a]);
      a++;
   }
}*/