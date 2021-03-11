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
}		        t_flags;

int				ft_printf(const char *str, ...);
char            ft_is_type(const char *str, int i);
t_flags         ft_manage_flags(const char *str, int i, t_flags flags, va_list args);
int				ft_conversion_c(unsigned char c, int fd, t_flags flags);
int             ft_conversion_s(const char *s, t_flags flags);
int             ft_conversion_p(void *ptr, t_flags flags);
int             ft_conversion_num(int nb, int fd, t_flags flags);
int             ft_conversion_u(long long int nb, int fd, t_flags flags);
int             ft_conversion_x(long long int nb, t_flags flags);
int             ft_conversion_X(long long int nb, t_flags flags);
size_t          ft_strlen(const char *s);
int				ft_atoi(const char *nb);
char			*ft_itoa(int n);
char			*ft_llitoa(long long int n);
char			*ft_itoa_noneg(int n);
int				ft_isdigit(int c);
char            *ft_strdup(const char *src);
char            *ft_substr(char const *str, unsigned int start, size_t len);
int             ft_putchar_fd(unsigned char c, int fd);
long long int	ft_manage_nb(long long int nb);
int             ft_check_error(const char *str);
void	ft_free_ptr(char* ptr);

#endif
