NAME = so_long

SRCS = ./get_next_line/get_next_line_utils.c \
		./get_next_line/get_next_line.c \
		so_long.c

OBJS = ${SRCS:.c=.o}

HEADER = so_long.h

LIBFT	= libft/libft.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

FLAGS	= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
	make -C libft
	make -C mlx
	gcc $(MLX_FLAGS) -Imlx $(SRCS) $(LIBFT) -I. -o $(NAME)
	#gcc $(FLAGS) $(MLX_FLAGS) -Imlx $(SRCS) $(LIBFT) -I. -o $(NAME)

clean:
	make clean -C libft
	make clean -C mlx
	rm -f $(OBJS)

fclean:	 clean
	make fclean -C libft
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re