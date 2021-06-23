SRCS	= main.c ft_atoi.c ft_itoa.c ft_strlcpy.c ft_strlen.c

OBJS	= ${patsubst %.c,%.o,$(SRCS)}

HEADER	= push_swap.h

NAME 	= libpushswap.a

RM		= rm -f
GCCFLAG	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	${OBJS} ${HEADER}
			ar rcs ${NAME} $?

%.o	:	%.c
			gcc ${GCCFLAG} -c $< -o $@

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
