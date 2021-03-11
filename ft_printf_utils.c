/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 21:25:57 by user42            #+#    #+#             */
/*   Updated: 2021/03/11 17:08:57 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		slen;
	int		i;

	slen = 0;
	i = 0;
	while (src[slen] != '\0')
		slen++;
	dest = malloc(sizeof(char) * (slen + 1));
	if (!dest)
		return (0);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_atoi(const char *nb)
{
	unsigned int	i;
	int				signe;
	int				nmb;

	signe = 1;
	i = 0;
	nmb = 0;
	while (nb[i] == ' ' || (nb[i] >= 8 && nb[i] <= 13))
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			signe *= -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
		nmb = nmb * 10 + nb[i++] - '0';
	return (nmb * signe);
}

size_t	ft_strlen(const char *s)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*res;

	i = 0;
	if (!str)
		return (NULL);
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	res[0] = '\0';
	if (start > ft_strlen(str))
		return (res);
	while (str[start] && i < len)
	{
		res[i] = str[start];
		i++;
		start++;
	}
	res[i] = '\0';
	return (res);
}