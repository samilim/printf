/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 14:06:56 by salimon           #+#    #+#             */
/*   Updated: 2021/03/11 21:09:08 by user42           ###   ########.fr       */
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

char*	ft_putaddr(unsigned long long int addr)
{
	int i;
	const char *base_hex;
    //char buf[50/*ft_strlen(ft_llitoa(addr)) * 2*/];
	//char *buf;
	char *address;


	//i = sizeof(buf);
	i = ft_addr_len(addr);
	address = malloc(sizeof(char) * (i + 1));
	base_hex = "0123456789abcdef";
	while (i >= 0)
	{
		address[i] = base_hex[(addr % 16)];
		addr = addr / 16;
		i--;
	}
	/*{
		buf[i] = base_hex[(addr % 16)];
		addr = addr / 16;
		i--;
	}
	i = 0;
	while (buf[i] == '0' && buf[i])
		i++;ok*/
	/*while (buf[i])
		write(1, &buf[i++], 1);*/
	//address = ft_substr(buf, i , ft_strlen(buf + i));
	//write(1, (buf + i), ft_strlen(buf + i));
	//free(buf);
	return (address/*ft_strlen(buf + i) + 2*/);
}

void	ft_write_address(char* address, int len)
{
	write(1, "0x", 2);
	write (1, address, len);
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
#include <stdio.h>
int		ft_conversion_p(void *ptr, t_flags flags)
{
	unsigned long long int addr;
	int count;
	int	len;
	char *address;
	
	addr = (unsigned long long int)ptr;
	count = 0;
	address = ft_putaddr(addr);
	len = ft_strlen(address);
	if (flags.minus)
		ft_write_address(address, len);
	while (flags.width > 0 && ((count + len + 2) < flags.width))//((count + len) <= flags.width))
	{
		write(1, " ", 1);
		count++;
	}
	if (!flags.minus && ptr)
		ft_write_address(address, len);
	//count_addr = ft_putaddr(addr);
	free(address);
	return (count + len + 2 /*+ len - 1*/);
}

//CAS NULL
//print un caractere en trop dans certains cas