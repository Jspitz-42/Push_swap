/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 08:54:01 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/11 11:59:09 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushswap.h"


static t_list	*initialize_stack_a(int ac, char **av)
{
	t_list	*a;

	if (ac == 2)
		a = stock_the_chain_in_a(av[1]);
	else
		a = stock_multi_arg(ac, av);
	return (a);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (-1);
	else
		a = initialize_stack_a(ac, av);
	if (!a || ft_lstsize(a) < 2)
		return (ft_lstclear(&a), ft_printf("Error\n"), -1);
	if (ft_lstsize(a) < 6)
		sort_under_six(&a, &b);
	else
		sort_big(&a, &b);
	ft_printf("%t", a);
	return (ft_lstclear(&a), ft_lstclear(&b), 0);
}
