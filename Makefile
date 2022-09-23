# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocardos <jocardos@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 11:23:57 by jocardos          #+#    #+#              #
#    Updated: 2022/09/22 21:50:46 by jocardos         ###   ########.fr        #
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
#OPENGL			= -framework OpenGL -framework AppKit
LINUX				= -lXext -lX11 -lm

#Styles

SET_COLOR	= \e[39m
RED				= \e[31m
GREEN			= \e[32m
YELLOW		= \e[33m
BLUE			= \e[34m
MAGENTA		= \e[35m
CYAN			= \e[36m
GRAY			= \e[90m
L_RED			=	\e[91m
L_GREEN		=	\e[92m
L_YELLOW	=	\e[93m
L_BLUE		=	\e[94m
L_MAGENTA	=	\e[95m
L_CYAN		=	\e[96m
WHITE			= \e[97m
BG_GREEN	= \e[42;1;37m

#Sources

SRC_FILES			= so_long configuration utils construct_map generate_map

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
			@$(CC) $(CFLAGS) $(OBJ) $(HEADER) libft.a $(MINILIBXCC) $(LINUX) -o $(NAME)
			@echo -e "$(L_GREEN) => Success ✅$(SET_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(OBJF)
			@echo -e -n "$(L_GREEN)✓$(SET_COLOR)"
			@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@touch $(OBJF)

clean:
			@make clean -C $(LIBFT)
			@$(RM) -r $(OBJ_DIR)
			@$(RM) $(OBJF)
			@make clean -C $(MINILIBX)
			@echo -e -n "$(MAGENTA)[SO_LONG]:$(SET_COLOR)$(BLUE) Object files$(SET_COLOR)$(GREEN)  => Cleaned$(SET_COLOR)"
			@echo -e " 🗑️$(SET_COLOR)"
			@echo -e -n "$(MAGENTA)[MINILIBX]:$(SET_COLOR)$(BLUE) Object files$(SET_COLOR)$(GREEN)  => Cleaned$(SET_COLOR)"
			@echo -e " 🗑️$(SET_COLOR)"

fclean:		clean
			@make fclean -C $(LIBFT)
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