/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 12:26:58 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/18 13:34:18 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    init_stack(t_utils *stack)
{
    stack->listA = NULL;
    stack->listB = NULL;
    stack->max_bits = 0;
    stack->max = 0;
    stack->min = 0;
}