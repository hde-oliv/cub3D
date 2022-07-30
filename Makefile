SRC_DIR :=	sources
INC_DIR :=	headers
OBJ_DIR :=	objects

vpath %.c	sources			\
			sources/parse	\
			sources/error	\
			sources/game

SRC		:=	main.c \
			error.c textures.c \
			checklist.c convert_rows.c \
			validate_elements.c elements.c validate_map_utils.c \
			validate_map.c create_rows.c parse.c parse_utils.c \
			end_game.c game_utils.c initialize_game.c \
			raycasting.c run_game.c hooks.c movement.c \

OBJS	:=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
INCLS   :=	$(INC_DIR)

CC		:=	gcc

CFLAGS	+=	-Wall -Wextra -Werror
IFLAGS	+=	-I.
LFLAGS	+=	-L.
TFLAGS	+=	-g3
MFLAGS	+=	-lmlx_Linux -lXext -lX11 -lft -lm

RM		:=	rm -rf

NAME	:=	cub3D

MLX_DIR	:=	minilibx

LFT_DIR	:=	libft


all:		obj mlx lft $(NAME)

$(OBJ_DIR)/%.o: %.c
			$(CC) $(CFLAGS) $(TFLAGS) -c $< -o $@ $(IFLAGS)/$(INCLS) $(IFLAGS)/$(MLX_DIR) $(IFLAGS)/$(LFT_DIR)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(LFLAGS)/$(MLX_DIR) $(LFLAGS)/$(LFT_DIR) $(MFLAGS) -o $(NAME)

clean:
			$(MAKE) -C $(LFT_DIR) clean
			$(MAKE) -C $(MLX_DIR) clean
			$(RM) $(OBJS) $(OBJ_DIR)

fclean: 	clean
			$(MAKE) -C $(LFT_DIR) fclean
			$(RM) $(NAME)

re: 		fclean all

mlx:
			$(MAKE) -C $(MLX_DIR)

lft:
			$(MAKE) -C $(LFT_DIR)

obj:
			mkdir -p $(OBJ_DIR)

.PHONY: 	all clean fclean re obj mlx lft
