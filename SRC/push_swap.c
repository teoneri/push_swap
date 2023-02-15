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
    // t_list *stack_b;
    // int i = 0;

    ft_check_isint(argv, argc);
    stack_a = ft_read_argv(argv, argc - 1);
    ft_check_duplicates(stack_a);
    ft_reverse_rotate_list(&stack_a);
    while (stack_a != NULL)
    {
        printf("%d\n", *stack_a->content);
        stack_a = stack_a->next;
        return 1;
    }
}

