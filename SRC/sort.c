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



