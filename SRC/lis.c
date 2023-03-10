/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:02:01 by mneri             #+#    #+#             */
/*   Updated: 2023/02/24 14:02:08 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_lis(t_list **list, int size)
{
	int	*lis;
	int	*stack;
	int	i;
	int	j;

	lis = ft_calloc(sizeof(int), size);
	stack = ft_stack_to_array(list, size);
	i = 0;
	while (i < size)
	{
		lis[i] = 1;
		j = 0;
		while (j < i)
		{
			if (stack[i] > stack[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j++;
		}
		i++;
	}
	free(stack);
	return (lis);
}

int	*ft_get_sort_lis(t_list **stack_a, int size, int *stack)
{
	int	*lis;
	int	*arr;
	int	count;
	int	i;
	int	j;

	lis = ft_lis(stack_a, size);
	arr = ft_calloc(sizeof(int), (ft_getmax_arr(lis, size) + 1));
	count = ft_getmax_arr(lis, size);
	i = ft_lstsize((*stack_a)) - 1;
	j = ft_getmax_arr(lis, size) - 1;
	while (i > 0)
	{
		if (lis[i] == count)
		{
			arr[j] = stack[i];
			j--;
			count--;
		}
		i--;
	}
	free(lis);
	free(stack);
	return (arr);
}

void	ft_lis_to_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;
	int		*stack;
	int		*lis;
	int		i;

	stack = ft_stack_to_array(stack_a, ft_lstsize(*stack_a));
	lis = ft_get_sort_lis(stack_a, ft_lstsize(*stack_a), stack);
	i = 0;
	current = *stack_a;
	while (i < ft_lstsize(*stack_a))
	{
		if (lis[i] == *current->content)
		{
			ft_rotate_list(stack_a, 'a');
			current = *stack_a;
			i++;
		}
		else
		{
			ft_push_list(stack_b, stack_a, 'b');
			current = *stack_a;
		}
	}
	free(lis);
}
