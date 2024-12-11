/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 15:08:47 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/08 16:15:28 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	put_lst(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (lst)
	{
		i += ft_putstr("lst content = ");
		i += ft_putnbr(lst->content);
		i += ft_putchar('\n');
		lst = lst->next;
	}
	lst = temp;
	return (i);
}
