/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmota-si <bmota-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 10:25:26 by bmota-si          #+#    #+#             */
/*   Updated: 2023/08/22 13:00:44 by bmota-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    verification(t_utils *stack)//esta funcao vai verificar quando as listas estao ordenadas, em que posiçao o numero da lista B fica na lista A
{
    t_node *tmp = stack->listA;
    if(stack->listB->value > tmp->value)
        return (0);
    else
        return (1);
}

void    ft_sort_b(t_utils *stack, int shift)
{
    int size;
    int i;
    if((is_sorted(stack->listB) || sorted_is(stack->listB)) && is_sorted(stack->listA))
    {
        while(lstsize(stack->listB) > 0)
            if(verification(stack) == 0)
                ra(stack);
            else
                pa(stack);
        while(!is_sorted(stack->listA))//ATENÇAO FAZER UMA NOVA VARIAVEL PARA O INDEX DA LISTA E DEPOIS FAZER UMA FUNÇÃO PARA DIVIDIR A LISTA EM 2 PARA DESCOBRIR O CAMINHO MAIS RAPIDO
        {
            ra(stack);
        }
        return;
    }
    i = 0;
    size = lstsize(stack->listB);
    while(i < size && lstsize(stack->listB))
    {
        if((stack->listB->value & (1 << (shift + 1))) == 0)
            rb(stack);
        else
            pa(stack);
        i++;
    }
    
}

void    ft_alg(t_utils *stack)
{
    int i = 0;
    int j = 0;
    int size = 0;//Para o tamanho da lista
    //t_node *tmp = stack->listA;

    while(i <= stack->max_bits && (!is_sorted(stack->listA)) && lstsize(stack->listA))
    {
        size = lstsize(stack->listA);
        j = 0;
        while(j < size && (!is_sorted(stack->listA)) && lstsize(stack->listA))
        {
            if(((stack->listA->value >> i) & 1 ) == 0)//Compara o primeiro numero da lista com 1 em binario shiftado "i" vezes para a direita. Se for igual a 0 envia para a lista B.
                pb(stack);
            else//Se for igual a 1 envia para o fim da lista A
                ra(stack);
            j++;
        }
        ft_sort_b(stack, i);
        i++;
    }
}

void    ft_index(int *array, t_utils *stack)
{
    t_node *aux = stack->listA;
    int i = 0;
    
    while(aux)
    {
        i = 0;
        while(array)
        {
            if(aux->value == array[i])
            {
                aux->value = i;
                break;
            }
            i++;
        }
        aux = aux->next;
    }
}

void    index3(t_utils *stack)
{
    int *array;
    array = malloc(sizeof(int) * (lstsize(stack->listA) + 1));

    t_node *aux = stack->listA;
    int i = 0;
    while(aux)
    {
        array[i] = aux->value;
        aux = aux->next;
        i++;
    }

    ordenar(array, stack);
    //print_array(array);

    ft_index(array, stack);//Coloco todos os valores da lista com o valor do index no array
    
    get_min(stack);
    get_max(stack);//Obtenho o max para depois calcular o max_bits para saber em que bit posso parar.
    while((stack->max >> stack->max_bits) != 0)
        stack->max_bits++;
    ft_alg(stack);
    /* while(!is_sorted(&tmp))
    {
        t_node *aux = tmp;
        while(aux->next)
        {
            if(aux->value > aux->next->value)
            {
                int new;
                new = aux->value;
                aux->value = aux->next->value;
                aux->next->value = new;
            }
            else
                aux = aux->next;
        }
    } */
}

int main(int ac, char **av)
{
    t_utils *stack;
    stack = malloc(sizeof(t_utils));
    int i = 1;
    
    if(ac < 2)
        exit(1);
    init_stack(stack);
    while(av[i] != NULL)
    {
        t_node *new_node = malloc(sizeof(t_node));
        new_node->value = atoi(av[i]);
        new_node->next = NULL;
        if(stack->listA == NULL)
            stack->listA = new_node;
        else
        {
            t_node *aux = stack->listA;
            while(aux->next)
                aux = aux->next;
            aux->next = new_node;
        }
        i++;
    }
    t_node *tmp = stack->listA;
    while(tmp->next)
    {
        tmp->next->prev = tmp;
        tmp = tmp->next;
    }
    stack->listA->prev = tmp;
    if(lstsize(stack->listA) > 5)
        index3(stack);
    else
        simple(stack);
    /* tmp = stack->listA;
    while(tmp != NULL){
        if(tmp->next == NULL)
            printf("%d!", tmp->value);
        else
            printf("%d - ", tmp->value);
        tmp = tmp->next;
    } */
    return (1);
}