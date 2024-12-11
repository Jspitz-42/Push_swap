/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 08:30:13 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/11 14:57:31 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

static int	max_i_j(int i, int j)
{
	if (i > j)
		return (i);
	else
		return (j);
}

static int	reverse_i_j(int i, int j, t_list **a, t_list **b)
{
	int	size_a;
	int	size_b;

	size_a = ft_lstsize((*a)) - j;
	size_b = ft_lstsize((*b)) - i;
	if (size_a > size_b)
		return (size_a);
	return (size_b);
}

static int	get_the_pos_in_a(t_list **a, int b_content)
{
	int		index_a;
	t_list	*temp_a;

	temp_a = *a;
	index_a = 0;
	while (temp_a && temp_a->content > b_content)
	{
		index_a++;
		temp_a = temp_a->next;
	}
	return (index_a);
}

static t_save_op	*min_in_save(t_save_op **save)
{
	int	i;

	i = 0;
	(*save)->min = 0;
	while ((*save)->case_save[i])
	{
		if ((*save)->case_save[i] < (*save)->case_save[i + 1]
			&& (*save)->case_save[i] < (*save)->min_op_before)
		{
			(*save)->min++;
			(*save)->min_op_before = (*save)->case_save[i];
			(*save)->index_b_min = (*save)->index_b;
			(*save)->index_a_min = (*save)->index_a;
		}
		i++;
	}
	return ((*save));
}

t_save_op	*ft_min_op(t_list **a, t_list **b, t_save_op *save)
{
	t_list		*temp_b;

	save->index_b = 0;
	save->index_b_min = save->index_b;
	temp_b = *b;
	save->index_a = get_the_pos_in_a(a, temp_b->content);
	save->index_a_min = save->index_a;
	save->min_op_before = 100;
	while (temp_b)
	{
		save->index_a = get_the_pos_in_a(a, temp_b->content);
		save->case_save[0] = max_i_j(save->index_a, save->index_b);
		save->case_save[1] = reverse_i_j(save->index_b, save->index_a, a, b);
		save->case_save[2] = save->index_a + ft_lstsize((*a)) - save->index_b;
		save->case_save[3] = ft_lstsize((*b)) - save->index_a + save->index_b;
		save = min_in_save(&save);
		save->index_b++;
		temp_b = temp_b->next;
	}
	return (save);
}
