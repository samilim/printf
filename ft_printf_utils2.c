/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:59:35 by salimon           #+#    #+#             */
/*   Updated: 2021/03/17 15:19:48 by salimon          ###   ########.fr       */
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

int	ft_precision_zero(int len, t_flags flags)
{
	len = flags.width;
	while (flags.width--)
		write(1, " ", 1);
	return (len);
}