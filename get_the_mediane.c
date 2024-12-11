/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_mediane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:29:04 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/11 14:42:33 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

static void	ft_sort_int_tab(int *tab, int size)
{
	int	s;
	int	c;
	int	d;
	int	i;

	i = 0;
	while (i != size)
	{
		s = i +1;
		while (s < size)
		{
			if (tab[i] > tab[s])
			{
				c = tab[i];
				d = tab[s];
				tab[s] = c;
				tab[i] = d;
			}
		s++;
		}	
	i++;
	}
}	

int	get_mediane(t_list **a)
{
	t_list	*temp_a;
	int		mediane;
	int		*tab;
	int		size_tab;
	int		i;

	i = 0;
	temp_a = *a;
	size_tab = ft_lstsize((*a));
	tab = ft_calloc(size_tab, sizeof(int));
	while (temp_a)
	{
		tab[i++] = temp_a->content;
		temp_a = temp_a->next;
	}
	ft_sort_int_tab(tab, size_tab);
	if (size_tab % 2 != 0)
		size_tab++;
	mediane = tab[(size_tab / 2) - 1];
	ft_printf("mediane: %d\n", mediane);
	return (free(tab), mediane);
}