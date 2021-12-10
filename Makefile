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

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} -I ${INCLUDE} -c $< -o $@ -g3

$(NAME)	:	${OBJS}
	 gcc ${CFLAGS} ${OBJS} ${LIBS} -o ${NAME}

clean	:	
	rm -Rf build/

fclean	:	clean
	rm -f ${NAME}

re		:	fclean ${NAME}

bonus	:	${OBJS} $(OBJS_BONUS)
	gcc ${CFLAGS} ${LIBS} ${OBJS} ${OBJS_BONUS} -o ${NAME}

.PHONY	:	all clean fclean re bonus
