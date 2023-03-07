/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 11:50:48 by mneri             #+#    #+#             */
/*   Updated: 2023/03/01 11:50:50 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_getmax_arr(int *arr, int size)
{
	int	max;
	int	i;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (max < arr[i])
			max = arr[i];
		i++;
	}
	return (max);
}

int	*ft_stack_to_array(t_list **stack_a, int size)
{
	int		*stack;
	int		i;
	t_list	*current;

	current = *stack_a;
	i = 0;
	stack = malloc(sizeof(int) * size);
	while (current != NULL)
	{
		stack[i++] = *current->content;
		current = current->next;
	}
	return (stack);
}

int	ft_getmin_arr(int *arr, int size)
{
	int	max;
	int	i;

	i = 0;
	max = arr[i];
	while (i < size)
	{
		if (max > arr[i])
			max = arr[i];
		i++;
	}
	return (max);
}
