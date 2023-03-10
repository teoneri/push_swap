/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:27:51 by mneri             #+#    #+#             */
/*   Updated: 2023/03/07 15:27:53 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_restof_moves(char *arr, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strcmp(arr, "rb\n"))
		ft_rotate_list_ck(stack_a);
	else if (!ft_strcmp(arr, "rr\n"))
		ft_rotate_two_list_ck(stack_a, stack_b);
	else if (!ft_strcmp(arr, "rra\n"))
		ft_reverse_rotate_list_ck(stack_a);
	else if (!ft_strcmp(arr, "rrb\n"))
		ft_reverse_rotate_list_ck(stack_b);
	else if (!ft_strcmp(arr, "rrr\n"))
		ft_reverse_rotate_two_list_ck(stack_a, stack_b);
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}

int	ft_check_moves(char *arr, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (arr)
	{
		if (!ft_strcmp(arr, "sa\n"))
			ft_swap_list_ck(stack_a);
		else if (!ft_strcmp(arr, "sb\n"))
			ft_swap_list_ck(stack_b);
		else if (!ft_strcmp(arr, "ss\n"))
			ft_swap_two_list_ck(stack_a, stack_b);
		else if (!ft_strcmp(arr, "pa\n"))
			ft_push_list_ck(stack_a, stack_b);
		else if (!ft_strcmp(arr, "pb\n"))
			ft_push_list_ck(stack_b, stack_a);
		else if (!ft_strcmp(arr, "ra\n"))
			ft_rotate_list_ck(stack_a);
		else
			i = ft_restof_moves(arr, stack_a, stack_b);
		free(arr);
		if (i == 1)
			return (1);
		arr = get_next_line(0);
	}
	return (0);
}

int	ft_check_ifsorted(t_list **stack)
{
	t_list	*current;

	if (*stack == NULL)
		return (0);
	current = *stack;
	while (current->next != NULL)
	{
		if (*current->content > *current->next->content)
			return (1);
		current = current->next;
	}
	return (0);
}

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

int	main(int argc, char **argv)
{
	t_list			*stack_a;
	t_list			*stack_b;
	long int		*buff;
	char			*arr;

	stack_b = NULL;
	buff = ft_atoi_argv(argv, argc - 1);
	if (argc < 2)
	{
		free(buff);
		exit(0);
	}
	ft_check_args(argc, argv, &stack_a, buff);
	arr = get_next_line(0);
	if (ft_check_moves(arr, &stack_a, &stack_b) == 1)
	{
		free(buff);
		ft_freestack(stack_b);
		ft_freestack(stack_a);
		exit(0);
	}
	if (ft_check_ifsorted(&stack_a) == 0 && stack_b == NULL)
		ft_printf("OK\n");
	else if (ft_check_ifsorted(&stack_a) != 0 || stack_b != NULL)
		ft_printf("KO\n");
	free(buff);
	ft_freestack(stack_b);
	ft_freestack(stack_a);
}
