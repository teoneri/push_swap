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
    if(*(*stack_a)->content > *(*stack_a)->next->content && *(*stack_a)->content > *tail->content)
        ft_rotate_list(stack_a, 'a');
    else if(*(*stack_a)->content > *(*stack_a)->next->content)
        ft_swap_list(stack_a, 'a');
    else if(*(*stack_a)->content > *tail->content)
        ft_reverse_rotate_list(stack_a, 'a');
    else if(*(*stack_a)->next->content > *tail->content)
        ft_swap_list(stack_a, 'a');
    else 
        return;
}



void ft_sort_five(t_list **stack_a, t_list **stack_b)
{
    int max;
    int i;

    i = 0;
    ft_push_list(stack_b, stack_a, 'b');
    ft_push_list(stack_b, stack_a, 'b');
    ft_sort_three(stack_a);
    ft_push_list(stack_a, stack_b, 'a');
    while(i++ < 3)
    {
        max = ft_getmax(stack_a);
        if(max == *(*stack_a)->content)
            ft_rotate_list(stack_a, 'a');
        else if(max == *(*stack_a)->next->content)
            ft_swap_list(stack_a, 'a');
        else
            ft_reverse_rotate_list(stack_a, 'a');
        ft_push_list(stack_b, stack_a, 'b');
    }
    ft_sort_three(stack_a);
    ft_push_list(stack_a, stack_b, 'a');
    ft_push_list(stack_a, stack_b, 'a');
    if(*(*stack_a)->content < *(*stack_a)->next->content)
        ft_swap_list(stack_a, 'a');
}