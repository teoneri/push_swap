/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:40:58 by mneri             #+#    #+#             */
/*   Updated: 2023/02/15 14:41:00 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_reverse_rotate_list(t_list **list, char ab)
{
    t_list *head;
    t_list *tail;
    t_list *node;

    head = *list;
    node = head;
    while (node->next->next != NULL)
        node = node->next;
    tail = node->next;
    node->next = NULL;
    tail->next = head;
    *list = tail;
    if (ab == 'a')
        ft_printf("rra\n");
    else if (ab == 'b')
        ft_printf("rrb\n");
}

void    ft_reverse_rotate_two_list(t_list **stack_a, t_list **stack_b)
{
    ft_reverse_rotate_list(stack_a, 'a');
    ft_reverse_rotate_list(stack_b, 'b');
}

int ft_getmax(t_list **stack)
{
    int max;
    t_list *current;

    current = *stack;
    max = *(*stack)->content;
    while(current->next != NULL)
    {
        if(max < *current->next->content)
            max = *current->next->content;
        current = current->next;
    }
    return (max);
}

int ft_getmin(t_list **stack)
{
    int min;
    t_list *current;

    current = *stack;
    min = *(*stack)->content;
    while(current->next != NULL)
    {
        if(min > *current->next->content)
            min = *current->next->content;
        current = current->next;
    }
    return (min);
}