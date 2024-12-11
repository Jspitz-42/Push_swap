/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:55:10 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/11 14:22:42 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include"./libft/libft.h"

typedef struct s_save_op
{
	int					case_save[4];
	int					index_b_min;
	int					index_a_min;
	int					index_b;
	int					index_a;
	int					min_op_before;
	int					min;
}						t_save_op;

int				*stocked_the_arg(char *av);
t_list			*stock_the_chain_in_a(char	*arg_to_stock);
t_list			*stock_multi_arg(int ac, char **av);
int				check_if_twice(t_list *a);
long long int	ft_atoi_check(const char *nptr);
int				check_if_digit(char *s);
int				check_if_sorted_and_complet(t_list *a, int size_og);
int				check_if_sorted_and_complet_b(t_list *b);

void			swap_a(t_list **a, int j);
void			swap_b(t_list **b, int j);
void			swap_both(t_list **a, t_list **b);
t_list			*mini_swap(t_list *a_b);

void			push_b(t_list **a, t_list **b);
void			push_a(t_list **b, t_list **a);

void			rotate_a(t_list **a, int j);
void			rotate_b(t_list **b, int j);
void			rotate_rr(t_list **a, t_list **b);

void			reverse_rotate_a(t_list **a, int j);
void			reverse_rotate_b(t_list **b, int j);
void			reverse_rotate_both(t_list **a, t_list **b);

t_list			*sort_under_six(t_list **a, t_list **b);
void			sort_two(t_list **a);
void			sort_three(t_list **a);
void			revert_sort_three(t_list **b);
void			sort_four(t_list **a, t_list **b);
void			sort_five(t_list **a, t_list **b);
void			sort_big(t_list **a, t_list **b);

int				check_if_min_or_max(t_list	**a, t_list **b);
int				get_the_max(t_list *a_b);
int				get_the_minimal(t_list *a_b);
int				get_mediane(t_list **a);

void			case_max_i_j(t_list **a, t_list **b, int i, int j);
void			case_reverse_max_i_j(t_list **a, t_list **b, int i, int j);
void			case_a_up_b_down(t_list **a, t_list **b, int i, int j);
void			case_a_down_b_up(t_list **a, t_list **b, int i, int j);

t_save_op		*ft_min_op(t_list **a, t_list **b, t_save_op *save);
int				save_index_b(t_save_op **save);

#endif
