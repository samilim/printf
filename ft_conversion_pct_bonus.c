/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pct_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 22:55:08 by user42            #+#    #+#             */
/*   Updated: 2021/03/20 23:12:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_conversion_pct(t_flags flags)
{
	int count;

	count = 1;
	if (flags.minus)
		write(1, "%", 1);
	while (count < flags.width)
	{
		if (flags.zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		count++;
	}
	if (!flags.minus)
		write(1, "%", 1);
	return (count);
}
