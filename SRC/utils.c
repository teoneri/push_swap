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

int ft_get_num_moves_b(t_list **stack, int b_content)
{
    int count;
    int size;
    t_list *current;

    size = ft_lstsize(*stack) / 2;
    count = 0;
    current = *stack;

    while(*current->content != b_content)
    {
        current = current->next;
        count++;
    }
    if(count > size)
        count = (ft_lstsize(*stack) - count) * -1;
    return(count);
}


int ft_get_num_moves_a(t_list **stack_a, int b_content, int size_a)
{
    t_list *current = *stack_a;
    int closest_bigger_num = INT_MAX;
    int closest_bigger_num_index = -1;
    int i = 0;
    
    while (current)
    {
        int curr_num = *(int *)current->content;
        if (curr_num > b_content && curr_num < closest_bigger_num)
        {
            closest_bigger_num = curr_num;
            closest_bigger_num_index = i;
        }
        current = current->next;
        i++;
    }
    if (closest_bigger_num_index == -1)
        return ft_get_num_move_formax(stack_a, size_a); 
    if (closest_bigger_num_index > size_a / 2)
        return (closest_bigger_num_index - size_a); 
    else
        return closest_bigger_num_index; 
}