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
    t_list *tail;
    t_list *node;
    int i;
    int size;

    size = ft_lstsize(*list);
    i = 0;
    node = *list;
    tail = ft_lstlast(*list);
    tail->next = node;
    while(i <= size)
    {
        node = node->next;
        i++;
    }
    node->next = NULL;
    *list = tail;
    if(ab == 'a')
        ft_printf("rra\n");
    if(ab == 'b')
        ft_printf("rrb\n");
}

void    ft_reverse_rotate_two_list(t_list **stack_a, t_list **stack_b)
{
    ft_reverse_rotate_list(stack_a, 'a');
    ft_reverse_rotate_list(stack_b, 'b');
}