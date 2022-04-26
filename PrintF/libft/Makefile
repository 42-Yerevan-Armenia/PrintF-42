NAME		=	libft.a

SRCS		=	ft_atoi.c ft_itoa.c ft_strlen.c
	
OBJS		=	$(SRCS:.c=.o)

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra

AR			=	ar rcs

all:		$(NAME)

$(NAME):	$(OBJS)
				$(AR) $(NAME) $(OBJS)

clean:		
				$(RM) $(OBJS) $(OBJS_B)

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
	