/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_x.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:27:05 by salimon           #+#    #+#             */
/*   Updated: 2021/02/25 01:46:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_byte(int nb, char *nb_hex, t_flags flags)
{
	int count;

	count = 0;
	count = ft_strlen(nb_hex);
    if (flags.prefix)
        count += 2;
	if (flags.width > 0 && (flags.width >= flags.precision))
		return (flags.width);
	if (flags.precision > flags.width)
		return (flags.precision);
	return (count);
}

static int		ft_manage_postnb(char *buf, int nb, int i, int nb_len, t_flags flags)
{
	if (!flags.minus)
	{
		while (((flags.width - nb_len) > 0) && i < (flags.width - nb_len))//((i + 1) < (len - (nb_len + flags.space + flags.sign)))
		{
			if (flags.zero && flags.precision == -1)
				buf[i++] = '0';
			else
				buf[i++] = ' ';
		}
	}
	return (i);
}

static char *ft_manage_buffer(int nb, char* nb_hex, int nb_len, char *buf, t_flags flags)
{
	int i;
	int len;
	int prec_i;

	i = 0;
	len = ft_count_byte(nb, nb_hex, flags);
	prec_i = 0;
	i = ft_manage_postnb(buf, nb, i, nb_len, flags);
	while ((ft_strlen(nb_hex) + prec_i) < flags.precision)
	{
		buf[i++] = '0';
		prec_i++;
	}
	while (*nb_hex)
		buf[i++] = *nb_hex++;
	if (flags.minus)
    {
		while (i <= len)
			buf[i++] = ' ';
    }
	buf[i] = '\0';
	return (buf);
}

static char *ft_convert_hex(unsigned int nb, t_flags flags)
{   
    int i;
	const char *base_hex;
    char buf[ft_strlen(ft_llitoa(nb)) + 1];

	i = sizeof(buf) - 1;
	base_hex = "0123456789abcdef";
	while (i >= 0)
	{
		buf[i] = base_hex[(nb % 16)];
		nb = nb / 16;
		i--;
	}
	i = 0;
    return (buf);
}

int ft_conversion_x(unsigned int nb, t_flags flags)
{
    int len;
	int nb_len;
	char *buf;
	char *nb_hex;

	nb_hex = malloc(sizeof(char) * ft_strlen(ft_llitoa(nb)) + 1);
	nb_hex = ft_convert_hex(nb, flags);
	len = ft_count_byte(nb, nb_hex, flags);
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf || !nb_hex)
		return (0);
	if (flags.precision > ft_strlen(nb_hex))
		nb_len = flags.precision; //nb_len = partie hexée
	else
		nb_len = ft_strlen(nb_hex);
	buf = ft_manage_buffer(nb, nb_hex, nb_len, buf, flags);
    if (flags.prefix)
    {
	    write(1, "0x", 2);
        len += 2;
    }
	write (1, buf, len);
	free(buf);
    free(nb_hex);
	return (len);
}
