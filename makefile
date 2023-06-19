# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocastell <ocastell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 13:04:45 by tnard             #+#    #+#              #
#    Updated: 2023/04/29 19:59:13 by ocastell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRCS 	=	src/cub3D.c src/check_error.c src/errors_utils.c src/init_map.c src/utils.c src/key_input.c src/texture.c src/raycast.c src/raycast_draw.c\
			src/raycast_init.c src/raycast_utils.c  src/player.c src/minimap.c src/animation.c src/mouse_move.c src/tex_check.c
SRCS_B 	=	src_bonus/cub3D_bonus.c src_bonus/check_error_bonus.c src_bonus/errors_utils_bonus.c src_bonus/init_map_bonus.c src_bonus/utils_bonus.c\
			src_bonus/key_input_bonus.c src_bonus/texture_bonus.c src_bonus/raycast_bonus.c src_bonus/raycast_draw_bonus.c\
			src_bonus/raycast_init_bonus.c src_bonus/raycast_utils_bonus.c  src_bonus/player_bonus.c src_bonus/minimap_bonus.c src_bonus/animation_bonus.c\
			src_bonus/mouse_move_bonus.c src_bonus/tex_check_bonus.c

NAME		= cub3D
NAME_B		= cub3D_bonus
OBJS_DIR	= objs/
OBJS_DIR_B	= objs_b/
OBJS		= $(SRCS:.c=.o)
OBJS_B		= $(SRCS_B:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
OBJECTS_PREFIXED_B = $(addprefix $(OBJS_DIR_B), $(OBJS_B))
CC			= gcc -g
CC_FLAGS	= -Wall -Werror -Wextra
MLB_FLAGS	= libft/libft.a mlx/libmlx.a -no-pie -lm -lX11 -lXext
$(OBJS_DIR)%.o : %.c include/cub3d.h
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)src
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${BLU}[BUILD - $(NAME)]${RST} '$<' $(END)"

$(OBJS_DIR_B)%.o : %.c include/cub3d_bonus.h
	@mkdir -p $(OBJS_DIR_B)
	@mkdir -p $(OBJS_DIR_B)src_bonus
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${BLU}[BUILD - $(NAME_B)]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED) maker
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) $(MLB_FLAGS)
	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"

$(NAME_B): $(OBJECTS_PREFIXED_B) maker
	@$(CC) -o $(NAME_B) $(OBJECTS_PREFIXED_B) $(CC_FLAGS) $(MLB_FLAGS)
	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME_B)$(END)\n"

all: $(NAME)

bonus:	$(NAME_B)

maker:
	make -C mlx
	@make -C libft

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(OBJS_DIR_B)
	@make clean -C libft
	@echo "${GRN}[CLEAN]${RST} done"

fclean: clean
	@make clean -C mlx
	@make fclean -C libft
	@rm -f $(NAME)
	@rm -f $(NAME_B)
	@echo "${GRN}[FCLEAN]${RST} done"

re: fclean all

.PHONY:		all clean fclean re
