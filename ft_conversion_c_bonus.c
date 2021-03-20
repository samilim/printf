/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_c_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:47:38 by user42            #+#    #+#             */
/*   Updated: 2021/03/20 22:47:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conversion_c(unsigned char c, int fd, t_flags flags)
{
	int count;

	count = 1;
	if (flags.minus)
		write(fd, &c, 1);
	while (count < flags.width)
	{
		write(fd, " ", 1);
		count++;
	}
	if (!flags.minus)
		write(fd, &c, 1);
	return (count);
}
