SRCS		=	utils/ft_complex.c	utils/get_sequence_speed.c \
				utils/ft_arrays.c utils/mlx_utils.c\
				ft_floats.c julia_set2.c fractol.c graph.c main.c

SRCS_BONUS	=

OBJS		=	$(addprefix build/,${SRCS:.c=.o})

OBJS_BONUS	=	$(addprefix build/,${SRCS_BONUS:.c=.o})

NAME		=	fractol

CFLAGS		=	-Wall -Werror -Wextra

INCLUDE		=	includes/

LIBS		=	-lm -lXext -lX11

MY_LIBS		=	libs/libft/libft.a libs/minilibx-linux/libmlx.a libs/libdynamic_buffer/libdynamic_buffer.a

MAX_SPEED	=	50

all		:	$(NAME)

build/%.o	:	srcs/%.c
	@if [ ! -d $(dir $@) ]; then\
		mkdir -p $(dir $@);\
	fi
	cc ${CFLAGS} -I ${INCLUDE} -D MAX_SPEED=$(MAX_SPEED) -c $< -o $@ -g3

libs/libft/libft.a	:
	make -C libs/libft

libs/minilibx-linux/libmlx.a	:
	make -C libs/minilibx-linux

libs/libdynamicbuffer/libdynamicbuffer.a	:
	make -C libs/libdynamic_buffer

$(NAME)	:	${MY_LIBS} ${OBJS}
	 gcc ${CFLAGS} ${OBJS} ${MY_LIBS} ${LIBS} -o ${NAME}

clean	:
	rm -Rf build/
	make -C libs/libft clean
	make -C libs/minilibx-linux clean
	make -C libs/libdynamic_buffer clean

fclean	:	clean
	rm -f ${NAME}
	make -C libs/libft fclean
	make -C libs/minilibx-linux fclean
	make -C libs/libdynamic_buffer fclean

re		:	fclean ${NAME}

bonus	:	${MY_LIBS} ${OBJS} $(OBJS_BONUS)
	gcc ${CFLAGS} ${LIBS} ${OBJS} ${OBJS_BONUS} -o ${NAME}

.PHONY	:	all clean fclean re bonus
