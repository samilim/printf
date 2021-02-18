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
    int width_spec;
    int precision;
    int precision_spec;
    int l; //gere aussi ll 
    int h; //gere aussi hh
}		        t_flags;

int				ft_printf(const char *str, ...);

#endif
