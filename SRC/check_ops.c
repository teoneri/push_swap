/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:22:21 by mneri             #+#    #+#             */
/*   Updated: 2023/03/09 14:22:22 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_push_list_ck(t_list **new_list, t_list **push_list)
{
	t_list	*node_toadd;

	if (*push_list == NULL)
		return ;
	node_toadd = *push_list;
	*push_list = (*push_list)->next;
	node_toadd->next = *new_list;
	*new_list = node_toadd;
}

void	ft_swap_list_ck(t_list **stack)
{
	t_list	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	ft_rotate_list_ck(t_list **list)
{
	t_list	*tail;
	t_list	*node;

	if (*list == NULL)
		return ;
	node = *list;
	tail = ft_lstlast(*list);
	*list = (*list)->next;
	node->next = NULL;
	tail->next = node;
}

void	ft_swap_two_list_ck(t_list **stack_a, t_list **stack_b)
{
	ft_swap_list_ck(stack_a);
	ft_swap_list_ck(stack_b);
}

void	ft_rotate_two_list_ck(t_list **stack_a, t_list **stack_b)
{
	ft_rotate_list_ck(stack_a);
	ft_rotate_list_ck(stack_b);
}
