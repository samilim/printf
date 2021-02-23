/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:06:56 by salimon           #+#    #+#             */
/*   Updated: 2021/02/23 04:11:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddr(unsigned int addr, int fd)
{
    char buf[(sizeof(addr) * 2) + 2];
	const char *base_hex;
    size_t i;

	i = 0;
    buf[0] = '0';
    buf[1] = 'x';
	base_hex = "0123456789abcdef";
    while (i < sizeof(addr) * 2)
	{
        buf[i + 2] = base_hex[(addr >> ((sizeof(addr) * 2 - 1 - i) * 4)) & 0xf];
		i++;
    }
    write(fd, buf, sizeof(buf));
}

int		ft_conversion_p(void *ptr, int fd, t_flags flags)
{
	unsigned int addr;
	int count;
	int	len;
	
	addr = (unsigned int)ptr;
	count = 0;
	len = ft_strlen(ft_itoa(addr));
	if (flags.minus)
		ft_putaddr(addr, 1);
	while (flags.width > 0 && ((count + len) <= flags.width))
	{
		write(1, " ", 1);
		count++;
	}
	if (!flags.minus)
		ft_putaddr(addr, 1);
	return (count + len);
}