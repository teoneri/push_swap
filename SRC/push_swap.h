/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mneri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:24:40 by mneri             #+#    #+#             */
/*   Updated: 2023/01/24 12:24:43 by mneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     PUSH_SWAP_H
# define    PUSH_SWAP_H


#include "../ft_printf/ft_printf.h"



t_list *ft_read_argv(char **argv, int size);
void    ft_copy_array(int *arr1, int *arr2, int size);
void    ft_check_duplicates(t_list *stack_a);
void    ft_check_isint(char **argv, int size);
void    ft_check_intsize(char **argv, int size);
long int *ft_atoi_argv(char **argv, int size);
void ft_swap_list(t_list **stack, char ab);
void    ft_push_list(t_list **new_list, t_list **push_list, char ab);
void    ft_rotate_list(t_list **list, char ab);
void    ft_rotate_two_list(t_list **stack_a, t_list **stack_b);
void    ft_reverse_rotate_list(t_list **list, char ab);
void    ft_reverse_rotate_two_list(t_list **stack_a, t_list **stack_b);
int    ft_check_ifsorted(t_list **stack);
void   ft_sort_three(t_list **stack_a);
void ft_sort_five(t_list **stack_a, t_list **stack_b);
int ft_getmax(t_list **stack);
int ft_getmin(t_list **stack);
#endif