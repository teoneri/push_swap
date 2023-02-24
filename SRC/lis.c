/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:02:01 by mneri             #+#    #+#             */
/*   Updated: 2023/02/24 14:02:08 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    *ft_lis(t_list **list, int size)
{
    int *lis;
    int *stack;
    int i;
    int j;

    lis = malloc(sizeof(int) * size);
    stack = ft_stack_to_array(list, size);
    lis[0] = 1;
    i = 1;
    while (i < size) 
    {
        lis[i] = 1;
        j = 0;
        while (j < i) 
        {
            if (stack[i] > stack[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
            j++;
        }
        i++;
    }
    free(stack);
    return (lis);
}

int ft_getmax_arr(int *arr)
{
    int max;
    int i;

    i = 0;
    max = 0;
    while(arr[i])
    {
        if(max < arr[i])
            max = arr[i];
        i++;
    }
    return(max);
}

int *ft_get_sort_lis(t_list **stack_a, int size)
{
    int *lis;
    int *stack;
    int *arr;
    int count;
    int i;
    int j;

    lis = ft_lis(stack_a, size);
    stack = ft_stack_to_array(stack_a, size);
    arr = ft_calloc(sizeof(int), ft_getmax_arr(lis) + 2);
    arr[1] = stack[0];
    j = 2;
    count = 2;
    i = 1;
    while (i < ft_lstsize(*stack_a))
    {
        if (count == lis[i])
        {
            arr[j] = stack[i];
            j++;
            count++;
        }
        i++;
    }
    arr[0] = count - 1;
    i = 0;
    return (arr);
}