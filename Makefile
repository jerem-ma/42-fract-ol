SRCS		=	utils/ft_complex.c	utils/get_sequence_speed.c \
				utils/ft_arrays.c \
				julia_set.c main.c

SRCS_BONUS	=

OBJS		=	$(addprefix build/,${SRCS:.c=.o})

OBJS_BONUS	=	$(addprefix build/,${SRCS_BONUS:.c=.o})

NAME		=	fractol

CFLAGS		=	-Wall -Werror -Wextra

INCLUDE		=	includes/

LIBS		=	-lm

MY_LIBS		=	libs/libft/libft.a

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} -I ${INCLUDE} -c $< -o $@ -g3

libs/libft/libft.a	:
	make -C libs/libft

$(NAME)	:	${MY_LIBS} ${OBJS}
	 gcc ${CFLAGS} ${OBJS} ${MY_LIBS} ${LIBS} -o ${NAME}

clean	:
	rm -Rf build/
	make -C libs/libft clean

fclean	:	clean
	rm -f ${NAME}
	make -C libs/libft fclean

re		:	fclean ${NAME}

bonus	:	${MY_LIBS} ${OBJS} $(OBJS_BONUS)
	gcc ${CFLAGS} ${LIBS} ${OBJS} ${OBJS_BONUS} -o ${NAME}

.PHONY	:	all clean fclean re bonus
