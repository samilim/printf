/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:12:26 by salimon           #+#    #+#             */
/*   Updated: 2021/02/17 16:57:42 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_fd(unsigned char c, int fd, t_flags flags)
{
	int count;

	if (!(flags.minus))
	write(fd, &c, 1);
	count = 1;
	if (flags.minus)
	{
		if (flags.width_spec)
		{

		}
		else
			while (count <= flags.width)
			{
				write (fd, ' ', 1);
				count++;
			}
	}
	return (count);
}