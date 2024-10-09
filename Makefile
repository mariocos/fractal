CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes

NAME = fractol

SRCS =	main.c \
		rendering.c \
		struct_init.c \
		math_utils.c \
		libft_utils.c \
		error_handling.c \
		parsing.c \
		

OBJS = ${SRCS:.c=.o}

RM = rm -f

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -Lminilibx-linux -lmlx_Linux -lX11 -lXext -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
