/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:41:58 by mneri             #+#    #+#             */
/*   Updated: 2023/02/01 12:42:01 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	*ft_atoi_argv(char **argv, int size)
{
	long int	*arr;
	int			i;

	i = 0;
	arr = malloc(sizeof(long int) * size);
	while (i < size)
	{
		arr[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	i = 0;
	while (i < size)
	{
		if (arr[i] > 2147483647 || arr[i] < -2147483648)
		{
			ft_printf("%s", "Error\n");
			free(arr);
			exit(0);
		}
		i++;
	}
	return (arr);
}

t_list	*ft_read_argv(int size, long int *buff)
{
	int			i;
	t_list		*stack;
	t_list		*current;

	i = 1;
	stack = ft_lstnew(buff);
	current = stack;
	while (i < size)
	{
		current->next = ft_lstnew(&buff[i]);
		current = current->next;
		i++;
	}
	return (stack);
}

void	ft_check_duplicates(t_list *stack_a, long int *buff)
{
	t_list	*current;
	t_list	*head;

	head = stack_a;
	while (stack_a != NULL)
	{
		current = stack_a;
		while (current->next != NULL)
		{
			if (*stack_a->content == *current->next->content)
			{
				ft_printf("%s", "Error\n");
				stack_a = head;
				free(buff);
				ft_freestack(stack_a);
				exit(0);
			}
			current = current->next;
		}
		stack_a = stack_a->next;
	}
}

void	ft_check_isint(char **argv, int size, long int *buff)
{
	int	i;
	int	k;

	k = 0;
	i = 1;
	while (i < size)
	{
		while (argv[i][k] != '\0')
		{
			if (ft_isdigit(argv[i][k]) == 0)
			{
				ft_printf("%s", "Error\n");
				free(buff);
				exit(0);
			}
			k++;
		}
		k = 0;
		i++;
	}
}

void	ft_check_args(int ac, char **av, t_list **stk_a, long int *buff)
{
	ft_check_isint(av, ac, buff);
	*stk_a = ft_read_argv(ac - 1, buff);
	ft_check_duplicates(*stk_a, buff);
}
