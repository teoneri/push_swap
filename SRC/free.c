/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:51:17 by mneri             #+#    #+#             */
/*   Updated: 2023/03/08 13:51:20 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_freestack(t_list *stack)
{
	t_list	*current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}

void	ft_finish_and_free(t_list **stack_a, t_move *mov, int *tmp)
{
	ft_finish_sort(stack_a);
	free(tmp);
	free(mov->a);
	free(mov->b);
	free(mov);
}
