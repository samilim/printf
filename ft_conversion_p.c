/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:06:56 by salimon           #+#    #+#             */
/*   Updated: 2021/02/23 21:03:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
/*
char	*ft_delete_zero(char *buf)
{
	char res[sizeof(buf)];
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (buf[i] == '0' && i < sizeof(buf))
		i++;
	while (i < sizeof(buf))
	{
		res[j] = buf[i];
		i++;
		j++;
	}
	return (res);
}*/

void	ft_putaddr(unsigned long long int addr, int fd)
{
	int i;
	const char *base_hex;
    char buf[ft_strlen(ft_llitoa(addr))];

	i = sizeof(buf) - 1;
	base_hex = "0123456789abcdef";
	while (i >= 0)
	{
		buf[i] = base_hex[(addr % 16)];
		addr = addr / 16;
		i--;
	}
	i = 0;
	write(fd, "0x", 2);
	while (buf[i] == '0' && i < sizeof(buf))
		i++;
	while (buf[i])
		write(1, &buf[i++], 1);
}
/*
unsigned long long int	ft_manageptr(unsigned long long int ptr)
{
	unsigned long long int res;
	char *addr;
	char *addr_without_zero;
	int 	i;

	addr = ft_itoa(ptr);
	while(addr[i] == '0')
		i++;
	addr_without_zero = ft_substr(addr, i, ft_strlen(addr));
	res = atoi(addr_without_zero);
	return (res);
}*/

int		ft_conversion_p(void *ptr, int fd, t_flags flags)
{
	unsigned long long int addr;
	int count;
	int	len;
	
	addr = (unsigned long long int)ptr;
	count = 0;
	len = ft_strlen(ft_llitoa(addr));
	if (flags.minus)
		ft_putaddr(addr, 1);
	while (flags.width > 0 && ((count + len) <= flags.width))
	{
		write(1, " ", 1);
		count++;
	}
	if (!flags.minus)
		ft_putaddr(addr, 1);
	return (count + len - 1);
}