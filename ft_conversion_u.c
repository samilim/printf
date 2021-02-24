/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:11:29 by salimon           #+#    #+#             */
/*   Updated: 2021/02/24 22:12:36 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_div_nb(long long int n)
{
	int count;

	count = 0;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	count++;
	return (count);
}

long long int	ft_manage_nb(long long int nb)
{
	unsigned long long int res;
	char *buf;
	char *buf_without_zero;
	int 	i;

	buf = ft_llitoa(nb);
	while(buf[i] == '0')
		i++;
	buf_without_zero = ft_substr(buf, i, ft_strlen(buf));
	res = ft_atoi(buf_without_zero);
	return (res);
}

static int	ft_count_byte(long long int nb, t_flags flags)
{
	int count;

	count = ft_div_nb(nb);
	if (flags.width > 0 && (flags.width >= flags.precision))
		return (flags.width);
	if (flags.precision > flags.width)
		return (flags.precision);
	return (count);
}

static int		ft_manage_postnb(char *buf, long long int nb, int i, int nb_len, t_flags flags)
{
	if (!flags.minus)
	{
		while (((flags.width - nb_len) > 0) && i < (flags.width - nb_len))
		{
			if (flags.zero && flags.precision == -1)
				buf[i++] = '0';
			else
				buf[i++] = ' ';
		}
	}
	return (i);
}

static char	*ft_manage_buffer(long long int nb, char* nb_pos, int nb_len, char *buf, t_flags flags)
{
	int i;
	int len;
	int prec_i;

	i = 0;
	len = ft_count_byte(nb, flags);
	prec_i = 0;
	i = ft_manage_postnb(buf, nb, i, nb_len, flags);
	while ((ft_div_nb(nb) + prec_i) < flags.precision)
	{
		buf[i++] = '0';
		prec_i++;
	}
	while (*nb_pos)
		buf[i++] = *nb_pos++;
	if (flags.minus)
		while (i < len)
			buf[i++] = ' ';
	buf[i] = '\0';
	return (buf);
}

int		ft_conversion_u(long long nb, int fd, t_flags flags)
{
	int len;
	int nb_len;
	char *buf;
	char *nb_pos;

	nb = ft_manage_nb(nb);
	if (nb < 0)
		nb = (4294967295 + nb + 1);
	nb_pos = malloc(sizeof(ft_div_nb(nb)) + 1);
	nb_pos = ft_llitoa(nb);
	len = ft_count_byte(nb, flags);
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (0);
	if (flags.precision > ft_div_nb(nb))
		nb_len = flags.precision;
	else
		nb_len = ft_div_nb(nb);
	buf = ft_manage_buffer(nb, nb_pos, nb_len, buf, flags);
	write (fd, buf, len);
	free(buf);
	free(nb_pos);
	return (len);
}