/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:45:29 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/02 11:29:45 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*current;
	t_list	*next_node;

	if (!lst)
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	*lst = NULL;
}
