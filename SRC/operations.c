/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:52:01 by mneri             #+#    #+#             */
/*   Updated: 2023/02/02 12:52:03 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_swap_list(t_list **stack, char ab)
{
    t_list *temp;

    temp = *stack;
    *stack = (*stack)->next;
    temp->next = (*stack)->next;
    (*stack)->next = temp;
    if(ab == 'a')
        ft_printf("sa\n");
    if(ab == 'b')
        ft_printf("sb\n");
}

void    ft_swap_two_list(t_list **stack_a, t_list **stack_b)
{
    ft_swap_list(stack_a, 't');
    ft_swap_list(stack_b, 't');
    ft_printf("ss");
}

void    ft_push_list(t_list **new_list, t_list **push_list, char ab)
{
    t_list *nodeToAdd;

    if(push_list == NULL)
        return;
    nodeToAdd = *push_list;
    *push_list = (*push_list)->next;
    nodeToAdd->next = *new_list;
    *new_list = nodeToAdd;
    if(ab == 'a')
        ft_printf("pa\n");
    if(ab == 'b')
        ft_printf("pb\n");
}

void    ft_rotate_list(t_list **list, char ab)
{
    t_list *tail;
    t_list *node;
    
    node = *list;
    tail = ft_lstlast(*list);
    *list = (*list)->next;
    node->next = NULL;
    tail->next = node;
    if(ab == 'a')
        ft_printf("ra\n");
    if(ab == 'b')
        ft_printf("rb\n");
}

void    ft_rotate_two_list(t_list **stack_a, t_list **stack_b)
{
    ft_rotate_list(stack_a, 't');
    ft_rotate_list(stack_b, 't');
    ft_printf("rr");
}