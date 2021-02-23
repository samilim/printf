#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef	struct 	s_flags
{
    int minus;
    int sign;
	int zero;
    int space;
    int prefix;
    int width;
    int precision;
    int l; //gere aussi ll 
    int h; //gere aussi hh
}		        t_flags;

int				ft_printf(const char *str, ...);
char            ft_is_type(const char *str, int i);
t_flags         ft_manage_flags(const char *str, int i, t_flags flags, va_list args);
int				ft_conversion_c(unsigned char c, int fd, t_flags flags);
int             ft_conversion_s(const char *s, t_flags flags);
int             ft_conversion_p(void *ptr, int fd, t_flags flags);
size_t          ft_strlen(const char *s);
int				ft_atoi(const char *nb);
char			*ft_itoa(int n);
int				ft_isdigit(int c);
int             ft_putchar_fd(unsigned char c, int fd);

#endif
