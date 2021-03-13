/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 19:22:50 by user42            #+#    #+#             */
/*   Updated: 2021/03/13 17:13:03 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_count(int n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*ft_create_nb(char *nb, int n, unsigned int i,
				unsigned int count)
{
	unsigned int len;

	len = count;
	while (len > i)
	{
		nb[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (nb);
}

char			*ft_itoa(int n)
{
	unsigned int	i;
	unsigned int	count;
	char			*nb;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	count = ft_count(n);
	if (!(nb = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		nb[i] = '-';
		i++;
		n = n * -1;
	}
	nb[count] = '\0';
	return (ft_create_nb(nb, n, i, count));
}

char			*ft_itoa_noneg(int n)
{
	unsigned int	i;
	unsigned int	count;
	char			*nb;

	if (n == -2147483648)
		return (ft_strdup("2147483648"));
	count = ft_count(n);
	if (!(nb = (char *)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	//nb /0
	i = 0;
	if (n < 0)
	{
		n = n * -1;
		count--;
	}
	nb[count] = '\0';
	return (ft_create_nb(nb, n, i, count));
}