/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 06:44:52 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/07 15:19:51 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/**
* @brief this function detect witch flag is sent
*		 to ft_printf and call the corresponding
*		 function to print it
*
*
* @param form the character of the flag after the %
* @param arg the last arg in the va_list, would be
*		 the s being writted if first flag for exemple
*
* @return the nbr of character printed by the called
*		  function 
*/
static int	form_conv(char form, va_list arg)
{
	if (form == 'c')
		return (ft_putchar((char) va_arg(arg, int)));
	else if (form == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (form == 'p')
		return (ft_pointer(va_arg(arg, void *)));
	else if (form == 'd' || form == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (form == 'u')
		return (ft_putnbr_unsigned(va_arg(arg, unsigned int)));
	else if (form == 'x' || form == 'X')
		return (ft_print_hexa(form, va_arg(arg, unsigned int)));
	else if (form == '%')
		return (ft_putchar('%'));
	else if (form == 't')
		return (put_lst(va_arg(arg, t_list *)));
	return (0);
}

/**
* @brief like printf, write an array and, depending of flag, can
*		 print various arg add to the list by the function va_arg
*
* @param s the chain to be print at first
* @param ... the dot come with va_arg lib and mneans various
*			 and yet to define argument
*
* @return the number of printed character
*/
int	ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;
	int		nb;

	if (!s)
		return (-1);
	va_start(arg, s);
	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			nb += form_conv(s[i++ + 1], arg);
		else
			nb += ft_putchar(s[i]);
		i++;
	}
	return (va_end(arg), nb);
}
