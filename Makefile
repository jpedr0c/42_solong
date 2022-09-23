# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocardos <jocardos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 11:23:57 by jocardos          #+#    #+#              #
#    Updated: 2022/09/23 16:07:03 by jocardos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL			= /bin/bash

NAME				= so_long
INC					= inc
HEADER			= -I inc
LIBFT				= libraries/libft/
MINILIBX		= libraries/minilibx/
SRC_DIR			= source/
OBJ_DIR			= object/
CC					= gcc
CFLAGS			= -Wall -Werror -Wextra -o -L..
FSANITIZE		= -fsanitize=address -g3
RM					= rm -f
MINILIBXCC	= -I mlx -L libraries/minilibx -lmlx
OPENGL			= -framework OpenGL -framework AppKit
#LINUX				= -lXext -lX11 -lm

#Styles

SET_COLOR	= \033[0:39m
RED				= \033[0;31m
GREEN			= \033[0;32m
YELLOW		= \033[0;33m
BLUE			= \033[0;34m
MAGENTA		= \033[0;35m
CYAN			= \033[0;36m
GRAY			= \033[0;90m
L_RED			=	\033[0;91m
L_GREEN		=	\033[0;92m
L_YELLOW	=	\033[0;93m
L_BLUE		=	\033[0;94m
L_MAGENTA	=	\033[0;95m
L_CYAN		=	\033[0;96m
WHITE			= \033[0;97m
BG_GREEN	= \033[42;1;37m

#Sources

SRC_FILES			= so_long configuration utils construct_map generate_map events checking_map validation_map

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

start:
			@echo -e -n "$(YELLOW)[Dependencies]:$(SET_COLOR)"
			@echo -e -n "$(WHITE)[$(SET_COLOR)"
			@make all

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJF)
			@echo -e -n "$(WHITE)]$(SET_COLOR)"
			@echo -e -n "$(L_GREEN) => 100% ✅$(SET_COLOR)\n"
			@make -C $(LIBFT)
			@cp libraries/libft/libft.a .
			@make -s -C $(MINILIBX)
			@echo -e -n "$(YELLOW)[MINILIBX]:$(SET_COLOR)"
			@echo -e "$(L_GREEN) => Success ✅$(SET_COLOR)"
			@echo -e -n "$(YELLOW)[SO_LONG]:$(SET_COLOR)"
			@$(CC) $(CFLAGS) $(OBJ) $(HEADER) $(MINILIBXCC) $(OPENGL) -o $(NAME) libft.a 
			@echo -e "$(L_GREEN) => Success ✅$(SET_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@echo -e -n "$(L_GREEN)✓$(SET_COLOR)"
			@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@touch $(OBJF)

clean:
			@make clean -s -C $(LIBFT)
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)
			@make clean -s -C $(MINILIBX)
			@echo -e -n "$(MAGENTA)[SO_LONG]:$(SET_COLOR)$(BLUE) Object files$(SET_COLOR)$(GREEN)  => Cleaned$(SET_COLOR)"
			@echo -e " 🗑️$(SET_COLOR)"
			@echo -e -n "$(MAGENTA)[MINILIBX]:$(SET_COLOR)$(BLUE) Object files$(SET_COLOR)$(GREEN)  => Cleaned$(SET_COLOR)"
			@echo -e " 🗑️$(SET_COLOR)"

fclean:		clean
			@make fclean -s -C $(LIBFT)
			@$(RM) $(NAME)
			@$(RM) libft.a
			@echo -e -n "$(MAGENTA)[LIBFT]:$(SET_COLOR)$(BLUE) Executable files$(SET_COLOR)$(GREEN)  => Cleaned$(SET_COLOR)"
			@echo -e " 🗑️$(SET_COLOR)"
			@echo -e -n "$(MAGENTA)[SO_LONG]:$(SET_COLOR)$(BLUE) Executable files$(GREEN)  => Cleaned$(SET_COLOR)"
			@echo -e " 🗑️$(SET_COLOR)"
			@echo -e -n "$(MAGENTA)[MINILIBX]:$(SET_COLOR)$(BLUE) Executable files$(GREEN)  => Cleaned$(SET_COLOR)"
			@echo -e " 🗑️$(SET_COLOR)"

re:		fclean all
			@echo -e "\n$(BG_GREEN) => Cleaned and rebuilt everything <= $(SET_COLOR)"

.PHONY:	all start clean fclean re