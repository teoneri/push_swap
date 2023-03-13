/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ops_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:51:55 by mneri             #+#    #+#             */
/*   Updated: 2023/03/09 13:51:57 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_reverse_rotate_list_ck(t_list **list)
{
	t_list	*head;
	t_list	*tail;
	t_list	*node;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	head = *list;
	node = head;
	while (node->next->next != NULL)
		node = node->next;
	tail = node->next;
	node->next = NULL;
	tail->next = head;
	*list = tail;
}

void	ft_reverse_rotate_two_list_ck(t_list **stack_a, t_list **stack_b)
{
	ft_reverse_rotate_list_ck(stack_a);
	ft_reverse_rotate_list_ck(stack_b);
}

void	ft_free_two_stack(t_list **stack_a, t_list **stack_b, long int *b)
{
	ft_freestack(*stack_a);
	ft_freestack(*stack_b);
	free(b);
}
