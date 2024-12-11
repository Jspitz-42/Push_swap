/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:41:16 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/10 15:09:21 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

int	check_if_sorted_and_complet(t_list *a, int size_og)
{
	t_list	*temp;

	temp = a;
	while (a->next)
	{
		if (a->content > a->next->content)
			a = a->next;
		else
			return (-1);
	}
	a = temp;
	if (ft_lstsize(a) != size_og)
		return (-1);
	else
		return (0);
}

int	check_if_sorted_and_complet_b(t_list *b)
{
	t_list	*temp;

	temp = b;
	while (b->next)
	{
		if (b->content < b->next->content)
			b = b->next;
		else
			return (-1);
	}
	b = temp;
	return (0);
}

long long int	ft_atoi_check(const char *nptr)
{
	long long int	r;
	int				i;
	int				pn;

	i = 0;
	r = 0;
	pn = 1;
	while (nptr[i] == 32 || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == 43 || nptr[i] == 45)
	{
		if (nptr[i++] == 45)
			pn = -1;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		r = r * 10 + (nptr[i] - 48);
		i++;
	}
	if ((r * pn) > INT_MAX || (r * pn) < INT_MIN
		|| (size_t)i < ft_strlen(nptr))
		return (-1);
	else
		return (0);
}

int	check_if_twice(t_list *a)
{
	int		temp;
	t_list	*abyss;

	while (a)
	{
		temp = a->content;
		abyss = a->next;
		while (abyss)
		{
			if (abyss->content == temp)
				return (-1);
			abyss = abyss->next;
		}
		a = a->next;
	}
	return (0);
}

int	check_if_digit(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (i == 0 && s[i] == '-')
			i++;
		if (s[i] < 48 || s[i] > 57)
			return (-1);
	}
	return (0);
}
