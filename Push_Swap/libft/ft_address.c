/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 12:53:52 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/29 12:53:52 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"

int	ft_print_hexa_extra(unsigned long nb)
{
	char	*hexa_num;
	int		count;

	count = 0;
	hexa_num = "0123456789abcdef";
	if (nb < 16)
		count += ft_print_char(hexa_num[nb]);
	if (nb >= 16)
	{
		count += ft_print_hexa_extra(nb / 16);
		count += ft_print_hexa_extra(nb % 16);
	}
	return (count);
}

int	ft_address(unsigned long nb)
{
	int	count;

	count = 0;
	if (!nb)
		return (write(1, "(nil)", 5));
	write (1, "0x", 2);
	count += ft_print_hexa_extra(nb);
	return (count + 2);
}
