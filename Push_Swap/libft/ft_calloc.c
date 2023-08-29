/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:59:25 by bmota-si          #+#    #+#             */
/*   Updated: 2022/11/18 14:58:54 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*A função aloca a memoria requerida e 
retorna o ponteiro para o espaco alocado,
ou NULL se o requerimento falhar a 
diferença entre malloc() e calloc() 
e que malloc nao zera a memoria alocada
CALLOC recebe 2 parametros, o primeiro e a quant de caracteres
que iremos salvar na memoria alocada, o segundo e quanto memoria
ocupa cada caracter. */

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
