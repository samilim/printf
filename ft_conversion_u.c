/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_u.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:11:29 by salimon           #+#    #+#             */
/*   Updated: 2021/03/15 14:32:20 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long int	ft_manage_nb(long long int nb)
{
	/*unsigned */long long int	res;
	char					*buf;
	char					*buf_without_zero;
	int						i;

	i = 0;
	buf = ft_llitoa(nb);
	while (buf[i] == '0')
		i++;
	buf_without_zero = ft_substr(buf, i, ft_strlen(buf));\
	free(buf);
	res = ft_atoi(buf_without_zero);
	free(buf_without_zero);
	return (res);
}

static int		ft_count_byte(long long int nb, t_flags flags)
{
	int count;

	count = ft_div_nb(nb);
	if (flags.width > 0 && (flags.width >= flags.precision)
	&& (flags.width > count))
		return (flags.width);
	if (flags.precision > flags.width &&
	flags.precision > count)
		return (flags.precision);
	return (count);
}

static int		ft_manage_postnb(char *buf, int i, int nb_len, t_flags flags)
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

static char		*ft_manage_buffer(long long int nb, char *nb_pos,
int nb_len, char *buf, t_flags flags)
{
	int i;
	int len;
	int prec_i;

	i = 0;
	len = ft_count_byte(nb, flags);
	prec_i = 0;
	i = ft_manage_postnb(buf, i, nb_len, flags);
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

int				ft_conversion_u(long long int nb, int fd, t_flags flags)
{
	int		len;
	int		nb_len;
	char	*buf;
	char	*nb_pos;

	if (flags.precision == 0 && nb == 0)
	{
		len = flags.width;
		while (flags.width--)
			write(1, " ", 1);
		return (len);
	}
	
	//nb = ft_manage_nb(nb);
	if (nb < 0)
		nb = (4294967295 + nb + 1); //apres manage nb
	//printf("\nnb = %lld \n", nb);
	nb = ft_manage_nb(nb);
	//printf("\nnb = %lld \n", nb);
	nb_pos = ft_llitoa(nb);
	len = ft_count_byte(nb, flags);
	if (!(buf = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (flags.precision > ft_div_nb(nb))
		nb_len = flags.precision;
	else
		nb_len = ft_div_nb(nb);
	buf = ft_manage_buffer(nb, nb_pos, nb_len, buf, flags);
	write(fd, buf, ft_strlen(buf));
	free(buf);
	free(nb_pos);
	return (len);
}
