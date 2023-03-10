/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:55:05 by mneri             #+#    #+#             */
/*   Updated: 2023/03/09 13:55:09 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     CHECKER_H
# define    CHECKER_H

# include "push_swap.h"

int		ft_check_moves(char *arr, t_list **stack_a, t_list **stack_b);
void	ft_push_list_ck(t_list **new_list, t_list **push_list);
void	ft_swap_list_ck(t_list **stack);
void	ft_rotate_list_ck(t_list **list);
void	ft_swap_two_list_ck(t_list **stack_a, t_list **stack_b);
void	ft_rotate_two_list_ck(t_list **stack_a, t_list **stack_b);
void	ft_reverse_rotate_list_ck(t_list **list);
void	ft_reverse_rotate_two_list_ck(t_list **stack_a, t_list **stack_b);

#endif
