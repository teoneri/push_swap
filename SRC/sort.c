/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:57:33 by mneri             #+#    #+#             */
/*   Updated: 2023/02/20 13:57:35 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_ifsorted(t_list **stack)
{
	t_list	*current;

	current = *stack;
	while (current->next != NULL)
	{
		if (*current->content > *current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}

void	ft_sort_three(t_list **stack_a)
{
	t_list	*tail;
	int		nxtcontent;
	int		content;

	nxtcontent = *(*stack_a)->next->content;
	content = *(*stack_a)->content;
	tail = ft_lstlast(*stack_a);
	while (ft_check_ifsorted(stack_a) != 0)
	{
		if (*(*stack_a)->content > nxtcontent && content > *tail->content)
			ft_rotate_list(stack_a, 'a');
		else if (content > nxtcontent)
			ft_swap_list(stack_a, 'a');
		else if (content > *tail->content)
			ft_reverse_rotate_list(stack_a, 'a');
		else if (nxtcontent > *tail->content)
			ft_swap_list(stack_a, 'a');
	}
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*tail;
	int		min;
	int		size;

	size = ft_lstsize(*stack_a);
	while (ft_lstsize(*stack_a) > 3)
	{
		tail = ft_lstlast(*stack_a);
		min = ft_getmin(stack_a);
		if (*(*stack_a)->content == min)
			ft_push_list(stack_b, stack_a, 'b');
		else if (*(*stack_a)->next->content == min)
		{
			ft_swap_list(stack_a, 'a');
			ft_push_list(stack_b, stack_a, 'b');
		}
		else if (*tail->content == min)
		{
			ft_reverse_rotate_list(stack_a, 'a');
			ft_push_list(stack_b, stack_a, 'b');
		}
		else
			ft_reverse_rotate_list(stack_a, 'a');
	}
	ft_help_sort_five(stack_a, stack_b, size);
}

void	ft_sort_big(t_list **stack_a, t_list **stack_b)
{
	t_move	*mov;
	int		*tmp;
	int		i;

	ft_lis_to_b(stack_a, stack_b);
	mov = ft_mov_a_b(stack_a, stack_b);
	i = 0;
	tmp = ft_get_tot_mov(mov, ft_lstsize(*stack_b));
	while (tmp[i] != ft_getmin_arr(tmp, ft_lstsize(*stack_b)))
		i++;
	ft_b_to_a(stack_a, stack_b, mov, tmp);
}

void	ft_b_to_a(t_list **stk_a, t_list **stk_b, t_move *mov, int *tmp)
{
	int	size_b;
	int	i;

	i = 0;
	size_b = ft_lstsize(*stk_b);
	while (*stk_b)
	{
		ft_ex_mvm(stk_a, stk_b, mov, i);
		ft_push_list(stk_a, stk_b, 'a');
		size_b--;
		if (*(*stk_a)->content == ft_getmax(stk_a))
			ft_rotate_list(stk_a, 'a');
		free(mov->a);
		free(mov->b);
		free(mov);
		free(tmp);
		mov = ft_mov_a_b(stk_a, stk_b);
		tmp = ft_get_tot_mov(mov, size_b);
		i = 0;
		while (tmp[i] != ft_getmin_arr(tmp, size_b))
			i++;
	}
	ft_finish_and_free(stk_a, mov, tmp);
}
