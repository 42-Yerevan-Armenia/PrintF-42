NAME		=	libftprintf.a

SRCS		=	ft_printf.c ft_printf_utils.c #ft_printf???.c

OBJS		=	$(SRCS:.c=.o)

LIBFTSRC	=	./libft/libft.a

LIBFT		=	./libft/.c

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra

AR			=	ar rcs

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C ./libft
			cp ./libft/libft.a $(NAME)
				$(AR) $(NAME) $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -L. -lftprintf
clean:
			$(MAKE) clean -C ./libft
			$(RM) $(OBJS)

fclean:		clean
				$(MAKE) fclean -C ./libft
				$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
