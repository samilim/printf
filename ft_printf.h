/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/19 16:33:32 by user42            #+#    #+#             */
/*   Updated: 2021/03/19 23:55:20 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct	s_flags
{
	int minus;
	int sign;
	int zero;
	int space;
	int prefix;
	int width;
	int precision;
}				t_flags;

int				ft_printf(const char *str, ...);
char			ft_is_type(const char *str, int i);
t_flags			ft_manage_flags(const char *str, int i,
t_flags flags, va_list args);
t_flags			ft_manage_width(const char *str, int i, t_flags flags, va_list args);
int				ft_conversion_c(unsigned char c, int fd, t_flags flags);
int				ft_conversion_s(const char *s, t_flags flags);
int				ft_conversion_p(void *ptr, t_flags flags);
int				ft_conversion_num(int nb, int fd, t_flags flags);
int				ft_conversion_u(long long int nb, int fd, t_flags flags);
int				ft_conversion_xlow(long long int nb, t_flags flags);
int				ft_conversion_xup(long long int nb, t_flags flags);
int				ft_conversion_ll(long long int nb, int fd, t_flags flags);
size_t			ft_strlen(const char *s);
long long int	ft_atoi(const char *nb);
char			*ft_itoa(int n);
char			*ft_llitoa(long long int n);
char			*ft_itoa_noneg(int n);
char			*ft_llitoa_noneg(long long int n);
int				ft_isdigit(int c);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *str, unsigned int start, size_t len);
int				ft_putchar_fd(unsigned char c, int fd);
t_flags			ft_cancel_zero(t_flags flags);
int				ft_precision_zero(int len, t_flags flags);
int				ft_div_nb(long long int nb);
char			*ft_convert_low_hex(long long int nb, char *buf);
char			*ft_convert_up_hex(long long int nb, char *buf);

#endif
