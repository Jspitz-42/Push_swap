/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 09:58:25 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/11 14:50:57 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	save_index_b(t_save_op **save)
{
	int	i;

	i = 0;
	(*save)->index_b_min = (*save)->case_save[i];
	while ((*save)->case_save[i])
	{
		if ((*save)->index_b_min > (*save)->case_save[i])
			(*save)->index_b_min = (*save)->case_save[i];
		i++;
	}
	return ((*save)->min);
}

void	revert_sort_three(t_list **b)
{
	int		min;
	int		max;

	min = get_the_minimal((*b));
	max = get_the_max((*b));
	while ((*b)->content != min)
	{
		if ((*b)->next->content == min)
			reverse_rotate_b(b, 1);
		else if ((*b)->next->next->content == min)
			rotate_b(b, 1);
	}
	if ((*b)->next->content == max)
		swap_b(b, 1);
}

static void	ft_apply_case(t_list **a, t_list **b, t_save_op *save)
{
	if (save->min == 0)
		case_max_i_j(a, b, save->index_b_min, save->index_a_min);
	else if (save->min == 1)
		case_reverse_max_i_j(a, b, save->index_b_min, save->index_a_min);
	else if (save->min == 2)
		case_a_up_b_down(a, b, save->index_b_min, save->index_a_min);
	else if (save->min == 3)
		case_a_down_b_up(a, b, save->index_b_min, save->index_a_min);
}

void	sort_big(t_list **a, t_list **b)
{
	t_save_op	*save;
	t_list		*last_b;
	int			mediane;

	save = malloc(sizeof(t_save_op) * 1);
	if (!save)
		return ;
	mediane = get_mediane(a);
	while (ft_lstsize((*a)) > 3)
	{
		push_b(a, b);
		last_b = ft_lstlast((*b));
		if (last_b->content > mediane)
			rotate_b(b, 1);
	}
	sort_three(a);
	while ((*b))
	{
		ft_min_op(a, b, save);
		ft_apply_case(a, b, save);
	}
	free(save);
}
