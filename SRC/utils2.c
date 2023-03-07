/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:21:46 by mneri             #+#    #+#             */
/*   Updated: 2023/03/01 14:21:47 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max_nbr(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	if (b > a)
		return (b);
	else
		return (a);
}

void	ft_sort_top(t_list *current, t_list **stack_a)
{
	while (*current->content != ft_getmax(stack_a))
	{
		ft_rotate_list(stack_a, 'a');
		current = *stack_a;
	}
	ft_rotate_list(stack_a, 'a');
}

void	ft_finish_sort(t_list **stack_a)
{
	t_list	*tail;
	int		i;
	int		size;
	t_list	*current;

	i = 0;
	size = ft_lstsize(*stack_a);
	current = *stack_a;
	tail = ft_lstlast(*stack_a);
	while (*current->content != ft_getmax(stack_a))
	{
		i++;
		current = current->next;
	}
	current = *stack_a;
	if (i > ft_lstsize(*stack_a) / 2)
	{
		while (*tail->content != ft_getmax(stack_a))
		{
			ft_reverse_rotate_list(stack_a, 'a');
			tail = ft_lstlast(*stack_a);
		}
	}
	else
		ft_sort_top(current, stack_a);
}
