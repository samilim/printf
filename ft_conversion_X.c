/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_X.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:05:03 by user42            #+#    #+#             */
/*   Updated: 2021/03/01 00:46:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_byte(long long int nb, char *nb_hex, t_flags flags)
{
	int count;

	count = 0;
	count = ft_strlen(nb_hex);
	if (flags.prefix && nb > 0)
        count += 2;
	if ((flags.width > count) && (flags.width >= flags.precision))
		return (flags.width);
	if ((flags.precision > flags.width) && (flags.precision > count))
		return (flags.precision);
	return (count);
}

static int		ft_manage_postnb(char *buf, int i, int nb_len, t_flags flags)
{
	if (!flags.minus)
	{
		//printf("width = %d, nb_len = %d\n", flags.width, nb_len);
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

static char *ft_manage_buffer(long long int nb, char* nb_hex, int nb_len_prec, char *buf, t_flags flags)
{
	int i;
	int len;
	int prec_i;
	int nb_len;

	i = 0;
	len = ft_count_byte(nb, nb_hex, flags);
	prec_i = 0;
	nb_len = ft_strlen(nb_hex);
	i = ft_manage_postnb(buf, i, nb_len_prec, flags);
	while ((nb_len + prec_i) < flags.precision)
	{
		buf[i++] = '0';
		prec_i++;
	}
	if (flags.prefix)
    {
		buf[i++] = '0';
		buf[i++] = 'X';
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

static char *ft_convert_hex(long long int nb)
{   
    int i;
	int j;
	const char *base_hex;
    char *buf;
	char *res;

	i = 0 ;
	j = 0;
	base_hex = "0123456789ABCDEF";
	if (nb < 0)
	    nb *= -1;
	//printf("%d\n", nb);
	buf = malloc(sizeof(char) * (ft_strlen(ft_llitoa(nb)) * 2 + 1));
	res = malloc(sizeof(char) * (sizeof(buf)) + 1);
	if (!buf || !res)
		return (NULL);
	while (nb >= 16)
	{
		buf[i] = base_hex[(nb % 16)];
		nb = nb / 16;
		i++;
	}
	buf[i] = base_hex[(nb % 16)];
	while (i >= 0)
		res[j++] = buf[i--];
	/*free(buf);
	free(res);*/
    return (res);
}

int ft_conversion_X(long long int nb, t_flags flags)
{
    int len;  // nb de bytes ecrits
	int nb_len; // len de la partie précisée
	char *buf; // contient buffer d'impression total (format flags + nb hex)
	char *nb_hex; //version char du nb hexé

	nb_hex = malloc(sizeof(char) * (ft_strlen(ft_convert_hex(nb)) + 1));
	nb_hex = ft_convert_hex(nb); //malloc necessaire ou pas? malloc len de convert hex?
	//printf("\n%lu\n",ft_strlen(nb_hex));
	len = ft_count_byte(nb, nb_hex, flags);
	nb_len = ft_strlen(nb_hex);
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf || !nb_hex)
		return (0);
	if (flags.precision > nb_len)
		nb_len = flags.precision;
	else
		nb_len = ft_strlen(nb_hex);
	buf = ft_manage_buffer(nb, nb_hex, nb_len, buf, flags);
	write (1, buf, len);
	free (buf);
	free(nb_hex);
	return (len);
}