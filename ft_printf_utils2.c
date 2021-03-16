/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:59:35 by salimon           #+#    #+#             */
/*   Updated: 2021/03/16 16:02:13 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_cancel_zero(t_flags flags)
{
	flags.zero = 0;
	return (flags);
}

int	ft_div_nb(long long int nb)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		nb = nb * -1;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	count++;
	return (count);
}