/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 11:37:22 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/11 11:52:32 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	reverse_rotate_a(t_list **a, int j)
{
	t_list	*temp_1;
	t_list	*temp_2;

	if (*a && (*a)->next)
	{
		temp_2 = (*a)->next;
		temp_1 = ft_lstlast((*a));
		temp_1->next = *a;
		(*a)->next = 0;
		*a = temp_2;
	}
	if (j == 1)
		ft_printf("rra\n");
}

void	reverse_rotate_b(t_list **b, int j)
{
	t_list	*temp_1;
	t_list	*temp_2;

	if (*b && (*b)->next)
	{
		temp_2 = (*b)->next;
		temp_1 = ft_lstlast((*b));
		temp_1->next = *b;
		(*b)->next = 0;
		*b = temp_2;
	}
	if (j == 1)
		ft_printf("rrb\n");
}


void	reverse_rotate_both(t_list **a, t_list **b)
{
	reverse_rotate_a(a, 0);
	reverse_rotate_b(b, 0);
	ft_printf("rrr\n");
}
