/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_application.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 10:42:21 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/11 14:01:46 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	case_max_i_j(t_list **a, t_list **b, int i, int j)
{
	while (i-- > 0 && j-- > 0)
		rotate_rr(a, b);
	while (i-- > 0)
		rotate_b(b, 1);
	while (j-- > 0)
		rotate_a(a, 1);
	push_a(b, a);
}

void	case_reverse_max_i_j(t_list **a, t_list **b, int i, int j)
{
	int	size_b;
	int	size_a;

	size_b = ft_lstsize((*b));
	size_a = ft_lstsize((*a));
	size_b -= i;
	size_a -= j;
	while (size_b-- > 0 && size_a-- >= 0)
		reverse_rotate_both(a, b);
	while (size_a-- > 0)
		reverse_rotate_b(b, 1);
	while (size_b-- > 0)
		reverse_rotate_a(a, 1);
	push_a(b, a);
}

void	case_a_up_b_down(t_list **a, t_list **b, int i, int j)
{
	int	rotation_numbers;
	int	size_a;

	size_a = ft_lstsize((*a));
	rotation_numbers = i + size_a - j;
	while (rotation_numbers-- > 0)
	{
		rotate_a(a, 1);
		reverse_rotate_b(b, 1);
	}
	push_a(b, a);
}

void	case_a_down_b_up(t_list **a, t_list **b, int i, int j)
{
	int	rotation_numbers;
	int	size_b;

	size_b = ft_lstsize((*b));
	rotation_numbers = size_b - i + j;
	while (rotation_numbers-- > 0)
	{
		reverse_rotate_a(a, 1);
		rotate_b(b, 1);
	}
	push_a(b, a);
}
