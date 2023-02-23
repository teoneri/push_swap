/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:57:33 by mneri             #+#    #+#             */
/*   Updated: 2023/02/20 13:57:35 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_check_ifsorted(t_list **stack)
{
    t_list *current;

    current = *stack;
    while(current->next != NULL)
    {
        if(*current->content > *current->next->content)
            return (1);
        current = current->next;
    }
    return (0);
}

void    ft_sort_three(t_list **stack_a)
{
    t_list *tail;

    tail = ft_lstlast(*stack_a);
    while(ft_check_ifsorted(stack_a) != 0)
    {    
        if(*(*stack_a)->content > *(*stack_a)->next->content && *(*stack_a)->content > *tail->content)
            ft_rotate_list(stack_a, 'a');
        else if(*(*stack_a)->content > *(*stack_a)->next->content)
            ft_swap_list(stack_a, 'a');
        else if(*(*stack_a)->content > *tail->content)
            ft_reverse_rotate_list(stack_a, 'a');
        else if(*(*stack_a)->next->content > *tail->content)
            ft_swap_list(stack_a, 'a');
    }
}

void ft_sort_five(t_list **stack_a, t_list **stack_b)
{
    t_list *tail;
    int min;
    int size;

    size = ft_lstsize(*stack_a);
    while(ft_lstsize(*stack_a) > 3)
    {
        tail = ft_lstlast(*stack_a);
        min = ft_getmin(stack_a);
        if(*(*stack_a)->content == min)
            ft_push_list(stack_b, stack_a, 'b');
        else if(*(*stack_a)->next->content == min)
        {
            ft_swap_list(stack_a, 'a');
            ft_push_list(stack_b, stack_a, 'b');
        }
        else if(*tail->content == min)
        {
            ft_reverse_rotate_list(stack_a, 'a');
            ft_push_list(stack_b, stack_a, 'b');
        }
        else
            ft_reverse_rotate_list(stack_a, 'a');
    }
    ft_sort_three(stack_a);
    ft_push_list(stack_a, stack_b, 'a');
    if(size == 5)
        ft_push_list(stack_a, stack_b, 'a');
}

int    *ft_stack_to_array(t_list **stack_a, int size)
{
    int *stack;
    int i;
    t_list *current;

    i = 0;
    stack = malloc(sizeof(int) * size);
    while(current != NULL)
    {
        stack[i++] = current->content;
        current = current->next;
    }
    return(stack);
}

void    ft_min_to_top(t_list **stack_a, int size)
{
    t_list *current;
    t_list *head;
    int half;
    int count;
    int min;

    count = 1;
    half = size / 2;
    head = *stack_a;
    current = *stack_a;
    min = ft_getmin(stack_a);
    while(*current ->content != min)
    {
        current->next;
        count++;
    }    
    if(count < half)
    {
        while(current != head)
            ft_rotate_list(stack_a, 'a');
    }
    if(count > half)
    {
        while(current != head)
            ft_reverse_rotate_list(stack_a, 'a');
    }
}

// int    ft_lis(t_list **stack, int size)
// {
//     int *lis;
//     int *stack;
//     int i = 1;
//     int j = 0;


//     stack = ft_stack_to_array(stack, size);
//     lis = malloc(sizeof(int) * size);
//     while(i < size)
//     {
//         lis[i] = 1;
//         while(j < i)
//         {
//             if(stack[i] > stack[j] && lis[i] < lis[j] + 1)
//                 lis[i] = lis[j] + 1;
//             j++;
//         }
//         i++;
//     }
// }