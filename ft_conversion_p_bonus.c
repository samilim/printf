/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salimon <salimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:06:56 by salimon           #+#    #+#             */
/*   Updated: 2021/03/20 17:55:23 by salimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_addr_len(unsigned long long int addr)
{
	int i;

	i = 0;
	while (addr >= 16)
	{
		addr = addr / 16;
		i++;
	}
	return (i);
}

char	*ft_putaddr(unsigned long long int addr)
{
	int			i;
	const char	*base_hex;
	char		*address;

	i = ft_addr_len(addr);
	address = malloc(sizeof(char) * (i + 2));
	base_hex = "0123456789abcdef";
	address[i + 1] = '\0';
	while (i >= 0)
	{
		address[i] = base_hex[(addr % 16)];
		addr = addr / 16;
		i--;
	}
	return (address);
}

void	ft_write_address(/*void *ptr, */char *address, int len)
{
	write(1, "0x", 2);
	write(1, address, len);
}


int		ft_conversion_p(void *ptr, t_flags flags)
{
	unsigned long long int	addr;
	int						count;
	int						len;
	char					*address;

	count = 0;
	if (flags.precision == 0 && ptr == NULL)
	{
		if (flags.minus)
			write(1, "0x", 2);
		while (count + 2 < flags.width)
		{
			write(1, " ", 1);
			count++;
		}
		if (!flags.minus)
			write(1, "0x", 2);
		return (count + 2);
	}
	addr = (unsigned long long int)ptr;
	address = ft_putaddr(addr);
	len = ft_strlen(address);
	if (flags.minus)
		ft_write_address(/*ptr, */address, len);
	while (flags.width > 0 && ((count + len + 2) < flags.width))
	{
		write(1, " ", 1);
		count++;
	}
	if (!flags.minus)
		ft_write_address(/*ptr, */address, len);
	free(address);
	return (count + len + 2);
}