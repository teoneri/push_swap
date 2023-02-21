/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:23:45 by mneri             #+#    #+#             */
/*   Updated: 2023/01/24 12:23:46 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *stack_a;
    t_list *stack_b;
    unsigned int lst_size;

    
    ft_check_isint(argv, argc);
    stack_a = ft_read_argv(argv, argc - 1);
    lst_size = ft_lstsize(stack_a);
    ft_check_duplicates(stack_a);
    if(ft_check_ifsorted(&stack_a) == 0)
    {
        ft_printf("stack is sorted");
        exit(0);
    }
    if(lst_size <= 3)
        ft_sort_three(&stack_a);
    if(lst_size == 5)
        ft_sort_five(&stack_a, &stack_b);
    // while (stack_a != NULL)
    // {
    //     printf("%d\n", *stack_a->content);
    //     stack_a = stack_a->next;
    // }
}

