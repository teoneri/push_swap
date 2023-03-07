/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 14:00:28 by mneri             #+#    #+#             */
/*   Updated: 2023/03/07 14:00:29 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr_rrr(t_list **stack_a, t_list **stack_b, t_move *mov, int i)
{
	if (mov->a[i] > 0 && mov->b[i] > 0)
	{
		ft_rotate_two_list(stack_a, stack_b);
		mov->a[i]--;
		mov->b[i]--;
	}
	else if (mov->a[i] < 0 && mov->b[i] < 0)
	{
		ft_reverse_rotate_two_list(stack_a, stack_b);
		mov->a[i]++;
		mov->b[i]++;
	}
}

void	ft_ra_rb(t_list **stack_a, t_list **stack_b, t_move *mov, int i)
{
	if (mov->b[i] > 0)
	{
		ft_rotate_list(stack_b, 'b');
		mov->b[i]--;
	}
	else if (mov->b[i] < 0)
	{
		ft_reverse_rotate_list(stack_b, 'b');
		mov->b[i]++;
	}
	else if (mov->a[i] > 0)
	{
		ft_rotate_list(stack_a, 'a');
		mov->a[i]--;
	}
	else if (mov->a[i] < 0)
	{
		ft_reverse_rotate_list(stack_a, 'a');
		mov->a[i]++;
	}
}

void	ft_ex_mvm(t_list **stack_a, t_list **stack_b, t_move *mov, int i)
{
	while (mov->a[i] != 0 || mov->b[i] != 0)
	{
		if ((mov->a[i] > 0 && mov->b[i] > 0)
			|| (mov->a[i] < 0 && mov->b[i] < 0))
			ft_rr_rrr(stack_a, stack_b, mov, i);
		else
			ft_ra_rb(stack_a, stack_b, mov, i);
	}
}

void	ft_help_sort_five(t_list **stack_a, t_list **stack_b, int size)
{
	ft_sort_three(stack_a);
	ft_push_list(stack_a, stack_b, 'a');
	if (size == 5)
		ft_push_list(stack_a, stack_b, 'a');
}

int	*ft_get_tot_mov(t_move *mov, int size_b)
{
	int	i;
	int	*tmp;

	i = 0;
	tmp = malloc(sizeof(int) * size_b);
	while (i < size_b)
	{
		if (mov->a[i] >= 0 && mov->b[i] >= 0)
			tmp[i] = ft_max_nbr(mov->a[i], mov->b[i]);
		else if (mov->a[i] <= 0 && mov->b[i] >= 0)
			tmp[i] = (mov->a[i] * -1) + mov->b[i];
		else if (mov->a[i] <= 0 && mov->b[i] <= 0)
			tmp[i] = ft_max_nbr(mov->a[i], mov->b[i]);
		else if (mov->a[i] >= 0 && mov->b[i] <= 0)
			tmp[i] = mov->a[i] + mov->b[i] * -1;
		i++;
	}
	return (tmp);
}
