/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_num.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:09:15 by salimon           #+#    #+#             */
/*   Updated: 2021/03/13 15:39:43 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_div_nb(int nb)
{
	int count;

	count = 0;
	if (nb == -2147483648)
		return (10);
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

static int	ft_count_byte(int nb, t_flags flags)
{
	int count;
	int f;

	count = 0;
	f = 0;
	if (nb < 0)
		flags.sign = 1;
	if ((nb < 0 || (nb >= 0 && (flags.sign || flags.space))))
		f++;
	count = ft_div_nb(nb);
	if (flags.width > 0 && (flags.width > count) && (flags.width >= flags.precision))
		return (flags.width);
	if (flags.precision > flags.width && flags.precision > count)
		return (f + flags.precision);
	return (count + f);
}

static int		ft_manage_postnb(char *buf, int nb, int i, int nb_len, t_flags flags)
{
	if (flags.space && (nb >= 0))
		buf[i++] = ' ';
	if (flags.space && nb < 0)
		flags.space = 0;
	if (nb < 0)
		flags.sign = 1;
	if (!flags.minus)
	{
		while (((flags.width - (nb_len + flags.sign)) > 0) && i < (flags.width - (nb_len + flags.sign)))//((i + 1) < (len - (nb_len + flags.space + flags.sign)))
		{
			if (flags.zero && flags.precision == -1)
			{
				if (flags.sign && nb < 0)
				{
					buf[i++] = '-';
					flags.sign = 0;
				}
				buf[i++] = '0';
			}
			else
				buf[i++] = ' ';
		}
	}
	if (flags.sign && nb >= 0)
		buf[i++] = '+';
	if (flags.sign && nb < 0)
		buf[i++] = '-';
	return (i);
}

#include <stdio.h>
static char	*ft_manage_buffer(int nb, char* nb_pos, int nb_len, char *buf, t_flags flags)
{
	int i;
	int len;
	int prec_i;
	int div_nb;

	i = 0;
	div_nb = ft_div_nb(nb);
	len = ft_count_byte(nb, flags);
	prec_i = 0;
	i = ft_manage_postnb(buf, nb, i, nb_len, flags);
	//printf("i = %d\n", i);
	/*printf("div_nb = %d\n", ft_div_nb(nb));
	printf("width = %d\n", flags.width);
	printf("precision = %d\n", flags.precision);*/
	while ((div_nb + prec_i) < flags.precision)
	{
		buf[i++] = '0';
		prec_i++;
	}
	while (*nb_pos)
		buf[i++] = *nb_pos++;
	if (flags.minus)
		while (i < len)
			buf[i++] = ' ';
	return (buf);
}

int		ft_conversion_num(int nb, int fd, t_flags flags)
{
	int len;
	int nb_len;
	char *buf;
	char *nb_pos;

	if (flags.precision == 0 && nb == 0)
	{
		len = flags.width;
		while (flags.width--)
			write (1, " ", 1);
		return (len);
	}
	nb_pos = ft_itoa_noneg(nb);
	len = ft_count_byte(nb, flags);
	//printf("\ncount byte = %d\n",len);
	if (!(buf = malloc(sizeof(char) * (len + 1))))
		return (0);
	buf[len] = '\0';
	if (flags.precision > ft_div_nb(nb))
		nb_len = flags.precision;
	else
		nb_len = ft_div_nb(nb);
	buf = ft_manage_buffer(nb, nb_pos, nb_len, buf, flags);
	write (fd, buf, len/*ft_strlen(buf) + 1*/);
	free(buf);
	free(nb_pos);
	return (len/*ft_strlen(buf)*/);
}