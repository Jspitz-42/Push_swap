/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:53:10 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/11 11:50:00 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	rotate_a(t_list **a, int j)
{
	t_list		*temp_1;
	t_list		*temp_2;

	if (*a && (*a)->next)
	{
		temp_1 = ft_lstlast(*a);
		temp_2 = *a;
		while (temp_2->next->next)
			temp_2 = temp_2->next;
		temp_2->next = NULL;
		ft_lstadd_front(a, temp_1);
		if (j == 1)
			ft_printf("ra\n");
	}
}

void	rotate_b(t_list **b, int j)
{
	t_list		*temp_1;
	t_list		*temp_2;

	if (*b && (*b)->next)
	{
		temp_1 = ft_lstlast(*b);
		temp_2 = *b;
		while (temp_2->next->next)
			temp_2 = temp_2->next;
		temp_2->next = NULL;
		ft_lstadd_front(b, temp_1);
		if (j == 1)
			ft_printf("rb\n");
	}
}

void	rotate_rr(t_list **a, t_list **b)
{
	rotate_a(a, 0);
	rotate_b(b, 0);
	ft_printf("rr\n");
}
