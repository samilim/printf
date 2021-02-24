/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:09:15 by salimon           #+#    #+#             */
/*   Updated: 2021/02/24 02:02:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//precion pour un int : nombre minimum de chiffres à  imprimer pour un entier (des 0 seront rajoutés en tête pour remplir le champ)

int	ft_div_nb(int nb)
{
	int count;

	count = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb >= 10)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_count_byte(int nb, t_flags flags)
{
	int count;
	int f;

	count = 0;
	f = 0;
	if ((nb >= 0 && (flags.sign || flags.space)))
		f++;
	count = ft_div_nb(nb);
	if (flags.width > 0 && (flags.width >= flags.precision))
		return (flags.width);
	if (flags.precision > flags.width)
		return (flags.precision + f);
	return (count + f);
}

int	ft_conversion_num(int nb, int fd, t_flags flags)
{
	int len;
	int i;
	int prec_i;
	char *buf;

	len = ft_count_byte(nb, flags);
	i = 0;
	prec_i = 0;
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (0);
	if (flags.space && nb >= 0)
	{
		buf[i] = ' ';
		i++;
	}
	if (!flags.minus)
	{
		while (i < len - (ft_div_nb(nb) + flags.space + flags.sign))
			buf[i++] = ' ';
	}
	while (ft_div_nb(nb) + prec_i <= flags.precision)
	{
		if (prec_i == 0 && nb < 0)
			write (1, "-", 1);
		write (1, "0", 1);
		prec_i++;
	}
	if (flags.sign && nb >= 0)
		buf[i] = '+';
	if (flags.minus)
	{
		while (i < len - (ft_div_nb(nb) + flags.space + flags.sign))
			buf[i++] = ' ';
	}
	buf + i = ft_itoa(nb);
	write (fd, buf, len);
	free(buf);
	return (len);
}