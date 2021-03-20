/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 16:58:20 by salimon           #+#    #+#             */
/*   Updated: 2021/03/20 17:01:06 by salimon          ###   ########.fr       */
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
        if(flags.zero)
            write(1, "0", 1);
        else
            write(1, " ", 1);
		count++;
	}
	if (!flags.minus)
		write(1, "%", 1);
	return (count);
}