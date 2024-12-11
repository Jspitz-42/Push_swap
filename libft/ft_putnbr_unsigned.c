/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 09:43:56 by jspitz            #+#    #+#             */
/*   Updated: 2024/11/30 07:14:34 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/**
* @brief even simplier putnbr for no negative to check
		 so no need to check int max problem,
*
* @param nb the unsigned int to print
*
* @return number of character printed
*/
int	ft_putnbr_unsigned(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb >= 10)
	{
		size += ft_putnbr_unsigned(nb / 10);
	}
	size += ft_putchar(nb % 10 + 48);
	return (size);
}
