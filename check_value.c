/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 13:03:04 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/10 15:15:17 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	check_if_min_or_max(t_list	**a, t_list **b)
{
	t_list	*temp_a;
	t_list	*temp_b;

	temp_a = ft_lstlast(*a);
	temp_b = *b;
	if (temp_a->content < temp_b->content)
		return (3);
	else
	{
		temp_b = ft_lstlast(*b);
		if (temp_a->content > temp_b->content)
			return (2);
		else
			return (1);
	}
}

int	get_the_minimal(t_list *a_b)
{
	int		min;
	t_list	*temp;

	temp = a_b;
	min = a_b->content;
	while (temp)
	{
		if (min > temp->content)
			min = temp->content;
		temp = temp->next;
	}
	temp = a_b;
	return (min);
}

int	get_the_max(t_list *a_b)
{
	int		max;
	t_list	*temp;

	temp = a_b;
	max = a_b->content;
	while (temp)
	{
		if (max < temp->content)
			max = temp->content;
		temp = temp->next;
	}
	temp = a_b;
	return (max);
}
