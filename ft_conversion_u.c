/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:11:29 by salimon           #+#    #+#             */
/*   Updated: 2021/02/18 16:15:12 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nb_count(int n)
{
	int count;

	count = 0;
    if (n < 0)
		n = n * -1;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

int		ft_putnbr_fd(int nb, int fd, t_flags flags)
{
	int count;

	count = ft_nb_count(nb);
	if (flags.minus && (nb >= 0))
		write (1, '+', 1);
	if (nb < 0)
		nb = 4294967295 - nb;
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10), fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
	else
		ft_putchar_fd(nb + '0', fd);
	return (count);
}