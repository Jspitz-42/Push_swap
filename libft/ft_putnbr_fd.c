/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jspitz <jspitz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:15:43 by jspitz            #+#    #+#             */
/*   Updated: 2024/12/04 15:04:03 by jspitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static int	nb_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_zero_or_max(int nb, int fd)
{
	if (nb == -2147483648)
		write(fd, "-2147483648", 11);
	if (nb == 0)
		write(fd, "0", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	i;
	int	size;
	int	nb;

	i = 0;
	size = nb_size(n);
	if (n == -2147483648 || n == 0)
	{
		ft_zero_or_max(n, fd);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	while (size > 0)
	{
		nb = n;
		i = 0;
		while (i++ < size - 1)
			nb /= 10;
		ft_putchar_fd(nb % 10 + 48, fd);
		size--;
	}
}
