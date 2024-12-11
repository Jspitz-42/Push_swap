/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_short_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 10:44:21 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/10 12:02:12 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

void	sort_two(t_list **a)
{
	if ((*a)->content < (*a)->next->content)
		swap_a(a, 1);
}

void	sort_three(t_list **a)
{
	int		min;
	int		max;

	min = get_the_minimal((*a));
	max = get_the_max((*a));
	while ((*a)->content != max)
	{
		if ((*a)->next->content == max)
			reverse_rotate_a(a, 1);
		else if ((*a)->next->next->content == max)
			rotate_a(a, 1);
	}
	if ((*a)->next->content == min)
		swap_a(a, 1);
}

void	sort_four(t_list **a, t_list **b)
{
	int		min;
	t_list	*temp;

	min = get_the_minimal((*a));
	temp = ft_lstlast((*a));
	if ((*a)->content == min)
		reverse_rotate_a(a, 1);
	else if ((*a)->next->content == min)
	{
		reverse_rotate_a(a, 1);
		reverse_rotate_a(a, 1);
	}
	else if (temp->content != min)
		swap_a(a, 1);
	push_b(a, b);
	sort_three(a);
	push_a(b, a);
}

void	sort_five(t_list **a, t_list **b)
{
	int		min;
	t_list	*temp;

	min = get_the_minimal((*a));
	temp = ft_lstlast((*a));
	if ((*a)->content == min)
		reverse_rotate_a(a, 1);
	else if ((*a)->next->content == min)
	{
		reverse_rotate_a(a, 1);
		reverse_rotate_a(a, 1);
	}
	else if ((*a)->next->next->content == min)
	{
		rotate_a(a, 1);
		swap_a(a, 1);
	}
	else if (temp->content != min)
		swap_a(a, 1);
	push_b(a, b);
	sort_four(a, b);
	push_a(b, a);
}

t_list	*sort_under_six(t_list **a, t_list **b)
{
	if (ft_lstsize((*a)) == 2)
		return (sort_two(a), (*a));
	else if (ft_lstsize((*a)) == 3)
		return (sort_three(a), (*a));
	else if (ft_lstsize((*a)) == 4)
		return (sort_four(a, b), (*a));
	else
		return (sort_five(a, b), (*a));
}
