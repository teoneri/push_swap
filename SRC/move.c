/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:11:30 by mneri             #+#    #+#             */
/*   Updated: 2023/03/07 15:11:32 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_get_num_moves_b(t_list **stack, int b_content)
{
	int		count;
	int		size;
	t_list	*current;

	size = ft_lstsize(*stack) / 2;
	count = 0;
	current = *stack;
	while (*current->content != b_content)
	{
		current = current->next;
		count++;
	}
	if (count > size)
		count = (ft_lstsize(*stack) - count) * -1;
	return (count);
}

int	ft_helpmov_a(t_list **stack_a, int cls_big_nb_index, int size_a)
{
	if (cls_big_nb_index == -1)
		return (ft_get_num_move_formax(stack_a, size_a));
	if (cls_big_nb_index > size_a / 2)
		return (cls_big_nb_index - size_a);
	else
		return (cls_big_nb_index);
}

int	ft_get_num_moves_a(t_list **stack_a, int b_content, int size_a)
{
	t_list	*current;
	int		cls_big_nb;
	int		cls_big_nb_index;
	int		i;
	int		curr_num;

	current = *stack_a;
	cls_big_nb = INT_MAX;
	cls_big_nb_index = -1;
	i = 0;
	while (current)
	{
		curr_num = *(int *)current->content;
		if (curr_num > b_content && curr_num < cls_big_nb)
		{
			cls_big_nb = curr_num;
			cls_big_nb_index = i;
		}
		current = current->next;
		i++;
	}
	i = ft_helpmov_a(stack_a, cls_big_nb_index, size_a);
	return (i);
}

int	ft_get_num_move_formax(t_list **stack_a, int size_a)
{
	int		count;
	t_list	*current;
	int		max_a;

	current = *stack_a;
	count = 0;
	max_a = ft_getmax(stack_a);
	while (*current->content != max_a)
	{
		current = current->next;
		count++;
	}
	count++;
	if (count == size_a)
		return (0);
	if (count > size_a / 2)
		count = (size_a - count) * -1;
	return (count);
}

t_move	*ft_mov_a_b(t_list **stack_a, t_list **stack_b)
{
	t_move	*move;
	int		i;
	t_list	*curr;
	int		size_a;
	int		size_b;

	size_b = ft_lstsize(*stack_b);
	i = 0;
	curr = *stack_b;
	move = ft_calloc(sizeof(t_move), 1);
	move->a = ft_calloc(sizeof(int), size_b);
	move->b = ft_calloc(sizeof(int), size_b);
	while (curr != NULL)
	{
		size_a = ft_lstsize(*stack_a);
		move->b[i] = ft_get_num_moves_b(stack_b, *curr->content);
		move->a[i] = ft_get_num_moves_a(stack_a, *curr->content, size_a);
		curr = curr->next;
		i++;
	}
	return (move);
}
