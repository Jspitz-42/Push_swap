/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:41:01 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/10 11:56:44 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	push_b(t_list **a, t_list **b)
{
	t_list	*temp_1;
	t_list	*temp_2;

	if (!a)
		return ;
	if ((*a)->next)
	{
		temp_1 = ft_lstlast(*a);
		temp_2 = *a;
		while (temp_2->next->next)
			temp_2 = temp_2->next;
		temp_2->next = NULL;
	}
	else
	{
		temp_1 = *a;
		*a = NULL;
	}
	ft_lstadd_back(b, temp_1);
	write(1, "pb\n", 3);
}

void	push_a(t_list **b, t_list **a)
{
	t_list	*temp_1;
	t_list	*temp_2;

	if (!b)
		return ;
	if ((*b)->next)
	{
		temp_1 = ft_lstlast(*b);
		temp_2 = *b;
		while (temp_2->next->next)
			temp_2 = temp_2->next;
		temp_2->next = NULL;
	}
	else
	{
		temp_1 = *b;
		*b = NULL;
	}
	ft_lstadd_back(a, temp_1);
	write(1, "pa\n", 3);
}
