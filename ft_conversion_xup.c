/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_xup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:27:05 by salimon           #+#    #+#             */
/*   Updated: 2021/03/20 17:34:46 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count_byte(long long int nb, char *nb_hex, t_flags flags)
{
	int count;

	count = 0;
	count = ft_strlen(nb_hex);
	if (flags.prefix && nb > 0)
		count += 2;
	if ((flags.width > count) && (flags.width >= flags.precision)
	&& (flags.width > count))
		return (flags.width);
	if ((flags.precision > flags.width)
	&& (flags.precision > count))
		return (flags.precision);
	return (count);
}

static int		ft_manage_postnb(char *buf, int i, int nb_len, t_flags flags)
{
	int prec_i;
	int nb_len_prec;

	prec_i = 0;
	if (flags.precision > nb_len)
		nb_len_prec = flags.precision;
	else
		nb_len_prec = nb_len;
	if (!flags.minus)
	{
		while (((flags.width - nb_len_prec) > 0)
		&& i < (flags.width - nb_len_prec))
		{
			if (flags.zero && flags.precision == -1)
				buf[i++] = '0';
			else
				buf[i++] = ' ';
		}
	}
	while ((nb_len + prec_i) < flags.precision)
	{
		buf[i++] = '0';
		prec_i++;
	}
	return (i);
}

static char		*ft_manage_buffer(long long int nb, char *nb_hex,
char *buf, t_flags flags)
{
	int i;
	int len;
	int nb_len;

	i = 0;
	nb_len = ft_strlen(nb_hex);
	len = ft_count_byte(nb, nb_hex, flags);
	i = ft_manage_postnb(buf, i, nb_len, flags);
	if (flags.prefix)
	{
		buf[i++] = '0';
		buf[i++] = 'X';
	}
	nb_len = 0;
	while (nb_hex[nb_len])
		buf[i++] = nb_hex[nb_len++];
	if (flags.minus)
		while (i <= len)
			buf[i++] = ' ';
	return (buf);
}

static char		*ft_nb_hex(long long int nb)
{
	int				i;
	long long int	j;
	char			*buf;
	char			*res;

	i = 1;
	if (nb < 0)
		nb *= (-1);
	j = nb;
	while (j >= 16 && i++)
		j = j / 16;
	if (!(buf = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	buf = ft_convert_up_hex(nb, buf);
	j = 0;
	if (!(res = malloc(sizeof(char) * (ft_strlen(buf) + 1))))
		return (NULL);
	i = ft_strlen(buf) - 1;
	while (i >= 0)
		res[j++] = buf[i--];
	res[j] = '\0';
	free(buf);
	return (res);
}

int				ft_conversion_xup(long long int nb, t_flags flags)
{
	int		len;
	char	*buf;
	char	*nb_hex;

	len = 0;
	if (flags.precision == 0 && nb == 0)
		return (ft_precision_zero(len, flags));
	if (flags.precision != (-1))
		flags = ft_cancel_zero(flags);
	nb_hex = ft_nb_hex(nb);
	len = ft_count_byte(nb, nb_hex, flags);
	if (!(buf = malloc(sizeof(char) * (len + 1))))
		return (0);
	buf[len] = '\0';
	buf = ft_manage_buffer(nb, nb_hex, buf, flags);
	write(1, buf, len);
	free(buf);
	free(nb_hex);
	return (len);
}
