SRCS	= push_swap.c ft_atoi.c ft_strlcpy.c ft_strlen.c ft_lstsize.c\
			ft_lstadd_back.c ft_split.c ft_substr.c ft_isdigit.c ft_lstnew.c free_clear.c\
			sa.c pa_pb.c rr.c ra_rb_rr.c index_mas_a.c razmetka1.c razmetka1_after_sa.c\
			razmetka2.c razmetka2_after_sa.c vibor_razmetki.c proverka_a_sa.c st_B_markirovka.c\
			st_B_min_mark.c mark_and_BtoA.c st_A_rovno.c checkAandPB.c create_steakA.c dublikat.c\
			ft_strnstr.c

SRCS_B	= push_swap_bonus.c ft_atoi.c ft_strlcpy.c ft_strlen.c ft_lstsize.c\
			ft_lstadd_back.c ft_split.c ft_substr.c ft_isdigit.c ft_lstnew.c free_clear.c\
			sa.c pa_pb.c rr.c ra_rb_rr.c index_mas_a.c razmetka1.c razmetka1_after_sa.c\
			razmetka2.c razmetka2_after_sa.c vibor_razmetki.c proverka_a_sa.c st_B_markirovka.c\
			st_B_min_mark.c mark_and_BtoA.c st_A_rovno.c checkAandPB.c create_steakA.c dublikat.c\
			bonus_utils.c ft_strnstr.c

OBJS	= $(SRCS:.c=.o)

OBJS_B	= $(SRCS_B:.c=.o)

HEADER	= push_swap.h

NAME 	= push_swap

NAME_B	= checker

RM	= rm -f

FLAG	= -Wall -Wextra -Werror

all:		$(NAME)

bonus:		$(NAME_B)

$(NAME):	$(OBJS) $(HEADER)
			gcc $(OBJS) ${FLAG} -o $(NAME)

$(NAME_B):	$(OBJS_B) $(HEADER)
			gcc $(OBJS_B) ${FLAG} -o $(NAME_B)

%.o	:	%.c $(HEADER)
			gcc ${FLAG} -c $< -o $@

clean:
			${RM} ${OBJS}
			${RM} ${OBJS_B}

fclean:		clean
			${RM} ${NAME}
			${RM} ${NAME_B}

re:			fclean all

.PHONY:		all clean fclean bonus re
