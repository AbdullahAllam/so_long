
NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MLX_PATH = mlx/

MLX_LIB = $(MLX_PATH)libmlx.a

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

LIBFT_PATH = libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

CFILES =	src/so_long.c\
			src/checkber.c\
			src/actions.c\
			src/all_destroy.c\
			src/status_destroy.c\
			src/all_initialize.c\
			src/map_initialize.c\
			src/kill.c\
			src/map_dimensions.c\
			src/map_get.c\
			src/check_map.c\
			src/build_map_matrix.c\
			src/modify.c\
			src/moves.c\
			src/checkvalidpath.c\
			src/checkvalidpathobject.c\
			src/graph.c\

OBJECTS = $(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<
	@printf $(UP)$(CUT)

subsystems:
	@echo $(B)
	make -C $(MLX_PATH) all
	@echo $(B)
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all
