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

# include "../ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_move
{
	int	*a;
	int	*b;
}	t_move;

t_list		*ft_read_argv(char **argv, int size);
void		ft_copy_array(int *arr1, int *arr2, int size);
void		ft_check_duplicates(t_list *stack_a);
void		ft_check_isint(char **argv, int size);
void		ft_check_intsize(char **argv, int size);
long int	*ft_atoi_argv(char **argv, int size);
void		ft_swap_list(t_list **stack, char ab);
void		ft_push_list(t_list **new_list, t_list **push_list, char ab);
void		ft_rotate_list(t_list **list, char ab);
void		ft_rotate_two_list(t_list **stack_a, t_list **stack_b);
void		ft_reverse_rotate_list(t_list **list, char ab);
void		ft_reverse_rotate_two_list(t_list **stack_a, t_list **stack_b);
int			ft_check_ifsorted(t_list **stack);
void		ft_sort_three(t_list **stack_a);
void		ft_sort_five(t_list **stack_a, t_list **stack_b);
int			ft_getmax(t_list **stack);
int			ft_getmin(t_list **stack);
int			*ft_lis(t_list **stack, int size);
int			*ft_stack_to_array(t_list **stack_a, int size);
int			*ft_get_sort_lis(t_list **stack_a, int size, int *stack);
void		ft_lis_to_b(t_list **stack_a, t_list **stack_b);
int			ft_getmax_arr(int *arr, int size);
t_move		*ft_mov_a_b(t_list **stack_a, t_list **stack_b);
int			ft_get_num_moves_a(t_list **stack_a, int b_content, int size_a);
int			ft_get_num_moves_b(t_list **stack, int b_content);
int			ft_get_num_move_formax(t_list **stack_a, int size_a);
void		ft_sort_big(t_list **stack_a, t_list **stack_b);
int			ft_getmin_arr(int *arr, int size);
int			ft_max_nbr(int a, int b);
void		ft_b_to_a(t_list **stk_a, t_list **stk_b, t_move *mov, int *tmp);
void		ft_finish_sort(t_list **stack_a);
void		ft_rr_rrr(t_list **stack_a, t_list **stack_b, t_move *mov, int i);
void		ft_ra_rb(t_list **stack_a, t_list **stack_b, t_move *mov, int i);
void		ft_ex_mvm(t_list **stack_a, t_list **stack_b, t_move *mov, int i);
int			*ft_get_tot_mov(t_move *mov, int size_b);
void		ft_help_sort_five(t_list **stack_a, t_list **stack_b, int size);
void		ft_check_args(int argc, char **argv, t_list **stack_a);
#endif