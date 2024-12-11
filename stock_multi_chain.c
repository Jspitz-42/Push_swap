/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_multi_chain.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 10:51:06 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/08 09:05:55 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

static int	check_all_arg(char **av)
{
	int	i;

	i = 1;
	while (av[i] != 0)
	{
		if (check_if_digit(av[i]) == -1)
			return (-1);
		i++;
	}
	return (i);
}

t_list	*stock_multi_arg(int ac, char **av)
{
	t_list	*a;
	t_list	*abbyss;

	a = NULL;
	if (check_all_arg(av) == -1)
		return (NULL);
	a = ft_lstnew(ft_atoi(av[ac-- - 1]));
	if (!a)
		return (NULL);
	abbyss = a;
	while (--ac > 0)
	{
		if (ft_atoi_check(av[ac]) == -1)
			return (ft_lstclear(&abbyss), NULL);
		a->next = ft_lstnew(ft_atoi(av[ac]));
		a = a->next;
	}
	if (check_if_twice(abbyss) == -1)
		return (ft_lstclear(&abbyss), NULL);
	return (abbyss);
}
