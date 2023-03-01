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

t_move    *ft_mov_a_b(t_list **stack_a, t_list **stack_b)
{
    t_move *move;
    int i;
    t_list *curr;

    i = 0;
    ft_lis_to_b(stack_a, stack_b);
    curr = *stack_b;
    move = malloc(sizeof(move));
    move->a = malloc(sizeof(int) * ft_lstsize(*stack_b));
    move->b = malloc(sizeof(int) * ft_lstsize(*stack_b));
    while(curr != NULL)
    {
        move->b[i] = ft_get_num_moves_b(stack_b, *curr->content);
        move->a[i] = ft_get_num_moves_a(stack_a, *curr->content, ft_lstsize(*stack_a));
        curr = curr->next;
        i++;
    }
    
    for(int j = 0; j < ft_lstsize(*stack_b); j++)
      { ft_printf("MOV_A %d MOV_A\n", move->a[j]);
        ft_printf("MOV_B %d MOV_B\n", move->b[j]);
      }
    return(move);
}

int ft_get_num_move_formax(t_list **stack_a, int size_a)
{
    int count;
    t_list *current;
    int max_a;

    current = *stack_a;
    count = 0;
    max_a = ft_getmax(stack_a);
    while(*current->content != max_a)
    {
        current = current->next;
        count++;
    }
    if(count > size_a / 2)
        count = (size_a - count) * -1;
    return(count);
}

int ft_getmin_arr(int *arr, int size)
{
    int max;
    int i;

    i = 0;
    max = 0;
    while(i < size)
    {
        if(max > arr[i])
            max = arr[i];
        i++;
    }
    return(max);
}

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
