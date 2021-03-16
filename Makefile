


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
			ft_conversion_Xup.c \
			ft_itoa.c\
			ft_llitoa.c \
			ft_manage_flags.c \
			ft_printf_utils.c \
			ft_printf_utils2.c \
			ft_printf.c \

SRCS_BONUS	= ft_conversion_c.c \
			ft_conversion_num.c \
			ft_conversion_p.c \
			ft_conversion_s.c \
			ft_conversion_u.c \
			ft_conversion_xlow.c \
			ft_conversion_Xup.c \
			ft_itoa.c\
			ft_llitoa.c \
			ft_manage_flags.c \
			ft_printf_utils.c \
			ft_printf_utils2.c \
			ft_printf.c \

SRCS_PATH	= srcs/
INC_PATH	= includes
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) $(IFLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

bonus:		$(OBJS) $(OBJS_BONUS)
			$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean
