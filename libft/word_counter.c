/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_counter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:54:54 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/07 17:21:23 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	word_counter(char const *s, char c)
{
	int	set;
	int	i;
	int	count;

	count = 0;
	i = 0;
	set = 1;
	while (s[i])
	{
		if (s[i] == c)
			set = 1;
		else if (set == 1)
		{
			set = 0;
			count++;
		}
		i++;
	}
	return (count);
}
