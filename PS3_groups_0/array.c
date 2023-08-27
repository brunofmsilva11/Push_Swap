/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:27:42 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/25 16:11:39 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap2(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    ordenar(int *array, t_utils *stack)
{
    int j = 0;

    while(j < lstsize(stack->listA))
    {
        if((array[j] > array[j + 1]) && (j + 1 < lstsize(stack->listA)))
        {
            swap2(&array[j], &array[j + 1]);
            j = 0;
        }
        else
            j++;
    }
}

void    print_array(int *array)
{
    int j = 0;
    while(array[j]){
        printf("%i - ", array[j]);
        j++;
    }
    printf("\n");
}

/* int main(int ac, char **av)
{
    int *array;
    int i = 1;
    int j = 0;

    array = malloc(sizeof(int) * ac);
    
    if(ac > 1)
    {
        while(av[i])
        {
            array[j] = atoi(av[i]);
            i++;
            j++;
        }
    }
    print_array(array);
    ordenar(array);
    printf("\n");
    print_array(array);
    
    return (0);
} */
