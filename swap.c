/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 03:33:23 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/11 12:18:06 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

t_list	*mini_swap(t_list *a_b)
{
	int	temp;

	if (!a_b || !a_b->next)
		return (a_b);
	temp = a_b->next->content;
	a_b->next->content = a_b->content;
	a_b->content = temp;
	return (a_b);
}

static t_list	*medium_swap(t_list *a_b)
{
	t_list	*antepenultiam;
	t_list	*before_last;
	t_list	*last;

	antepenultiam = a_b;
	before_last = antepenultiam->next->next;
	last = antepenultiam->next;
	antepenultiam->next = before_last;
	before_last->next = last;
	last->next = NULL;
	return (a_b);
}

void	swap_a(t_list **a, int j)
{
	t_list	*antepenultiam;
	t_list	*before_last;
	t_list	*last;

	if (!(*a) || !(*a)->next)
		return ;
	if (j == 1)
		write(1, "sa\n", 3);
	antepenultiam = *a;
	if (ft_lstsize((*a)) == 2)
		mini_swap((*a));
	else if (ft_lstsize((*a)) == 3)
		medium_swap((*a));
	else
	{
		while (antepenultiam->next->next && antepenultiam->next->next->next)
		{
			antepenultiam = antepenultiam->next;
			before_last = antepenultiam->next->next;
		}
		last = antepenultiam->next;
		antepenultiam->next = before_last;
		before_last->next = last;
		last->next = NULL;
	}
}

void	swap_b(t_list **b, int j)
{
	t_list	*antepenultiam;
	t_list	*before_last;
	t_list	*last;

	if (!b || !(*b)->next)
		return ;
	antepenultiam = *b;
	if (ft_lstsize((*b)) == 2)
		mini_swap((*b));
	else if (ft_lstsize((*b)) == 3)
		medium_swap((*b));
	else
	{
		while (antepenultiam->next->next && antepenultiam->next->next->next)
		{
			antepenultiam = antepenultiam->next;
			before_last = antepenultiam->next->next;
		}
		last = antepenultiam->next;
		antepenultiam->next = before_last;
		before_last->next = last;
		last->next = NULL;
	}
	if (j == 1)
		write(1, "sb\n", 3);
}

void	swap_both(t_list **a, t_list **b)
{
	swap_a(a, 1);
	swap_b(b, 1);
	write(1, "ss\n", 3);
}
