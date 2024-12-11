/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_one_chain.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 09:15:15 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/09 12:51:30 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"

static int	ft_consecutive_space(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == ' ' && s[i + 1] == ' ')
			return (-1);
		i++;
	}
	return (0);
}

static void	ft_free(char **new)
{
	unsigned int	i;

	i = -1;
	while (new[++i])
		free(new[i]);
	free(new);
}

static int	check_arg_if_one_chain(char **av)
{
	int	i;

	i = -1;
	while (av[++i])
	{
		if (check_if_digit(av[i]) == -1)
			return (-1);
	}
	return (0);
}

int	*stocked_the_arg(char *av)
{
	char	**stocked_arg;
	int		*verified_stock_arg;
	int		size;
	int		i;

	if (ft_consecutive_space(av) == -1)
		return (NULL);
	i = -1;
	size = word_counter(av, ' ');
	stocked_arg = ft_split(av, ' ');
	if (!stocked_arg)
		return (NULL);
	if (check_arg_if_one_chain(stocked_arg) == -1)
		return (ft_free(stocked_arg), NULL);
	verified_stock_arg = ft_calloc(size, sizeof(int));
	if (!verified_stock_arg)
		return (ft_free(stocked_arg), NULL);
	while (++i < size)
	{
		if (ft_atoi_check(stocked_arg[i]) == -1)
			return (ft_free(stocked_arg), NULL);
		verified_stock_arg[i] = ft_atoi(stocked_arg[i]);
	}
	return (ft_free(stocked_arg), verified_stock_arg);
}

t_list	*stock_the_chain_in_a(char	*arg_to_stock)
{
	t_list	*a;
	t_list	*abbyss;
	int		size;
	int		*stocked_arg;

	a = NULL;
	stocked_arg = stocked_the_arg(arg_to_stock);
	if (!stocked_arg)
		return (NULL);
	size = word_counter(arg_to_stock, ' ');
	a = ft_lstnew(stocked_arg[size-- - 1]);
	abbyss = a;
	while (--size >= 0)
	{
		a->next = ft_lstnew(stocked_arg[size]);
		a = a->next;
	}
	if (check_if_twice(abbyss) == -1)
		return (free(stocked_arg), ft_lstclear(&a), NULL);
	return (free(stocked_arg), abbyss);
}
