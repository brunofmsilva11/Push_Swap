/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:49:48 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 19:25:12 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* s: The string to output.
fd: The file descriptor on which to write.
Outputs the string ’s’ to the given file
descriptor. */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || fd < 0)
		return ;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}

/*int	main()
{
	char c[] = "Bruno";
	char *p;
	p=c;
	int fd = 1;
	
	ft_putstr_fd(p, fd);
}*/