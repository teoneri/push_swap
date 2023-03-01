/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:50:48 by mneri             #+#    #+#             */
/*   Updated: 2023/03/01 11:50:50 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_getmax_arr(int *arr, int size)
{
    int max;
    int i;

    i = 0;
    max = 0;
    while(i < size)
    {
        if(max < arr[i])
            max = arr[i];
        i++;
    }
    return(max);
}

void    ft_min_to_top(t_list **stack_a, int size, int min)
{
    t_list *current;
    int half;
    int count;
    int i;

    i = 1;
    count = 1;
    half = size / 2;
    current = *stack_a;
    while(*current ->content != min)
    {
        current = current->next;
        count++;
    }    
    if(count <= half)
    {
        while(i++ < count)
            ft_rotate_list(stack_a, 'a');
    }
    else if(count >= half)
    {
        i = size - count;
        while(i-- >= 0)
            ft_reverse_rotate_list(stack_a, 'a');
    }
}

int    *ft_stack_to_array(t_list **stack_a, int size)
{
    int *stack;
    int i;
    t_list *current;

    current = *stack_a;
    i = 0;
    stack = malloc(sizeof(int) * size);
    while(current != NULL)
    {
        stack[i++] = *current->content;
        current = current->next;
    }
    return(stack);
}