


NAME    = libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
AR 			= ar rcs
RM			= rm -f
IFLAGS		= -include printf.h

SRCS 		= ft_conversion_c.c \
			ft_conversion_num.c \
			ft_conversion_p.c \
			ft_conversion_s.c \
			ft_conversion_u.c \
			ft_conversion_xlow.c \
			ft_conversion_xup.c \
			ft_itoa.c\
			ft_llitoa.c \
			ft_manage_flags.c \
			ft_manage_width.c \
			ft_printf_utils.c \
			ft_printf_utils2.c \
			ft_printf.c \
			ft_conversion_ll.c \
			ft_conversion_pct.c \

SRCS_BONUS	= ft_conversion_c_bonus.c \
			ft_conversion_num_bonus.c \
			ft_conversion_p_bonus.c \
			ft_conversion_s_bonus.c \
			ft_conversion_u_bonus.c \
			ft_conversion_xlow_bonus.c \
			ft_conversion_xup_bonus.c \
			ft_itoa_bonus.c\
			ft_llitoa_bonus.c \
			ft_manage_flags_bonus.c \
			ft_manage_width_bonus.c \
			ft_printf_utils_bonus.c \
			ft_printf_utils2_bonus.c \
			ft_printf_bonus.c \
			ft_conversion_ll_bonus.c \
			ft_conversion_pct_bonus.c \

SRCS_PATH	= srcs/
INC_PATH	= includes
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

bonus:		$(OBJS_BONUS)
			$(AR) $(NAME) $(OBJS_BONUS)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean bonus
