# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocardos <jocardos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 11:23:57 by jocardos          #+#    #+#              #
#    Updated: 2022/09/08 17:55:33 by jocardos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL	= /bin/bash

NAME	= so_long
RM		= rm -f
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I

#Styles

SET_COLOR	= \033[0;39m
GREEN		= \033[0;32m
BLUE		= \033[0;34m
CYAN		= \033[0;36m
YELLOW		= \033[0;33m
BG_GREEN	= \033[42;1;37m

#Sources

SRC			= main.c
OBJ			= ${SRC:.c=.o}

.c.o:		%.o : %.c
			@${CC} ${CFLAGS} include -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
			@make -C ./libft
			@${CC} ${OBJ} -Llibft -lft -o ${NAME}
			@echo -e -n "$(YELLOW)PIPEX:$(SET_COLOR)"
			@echo -e -n " $(WHITE)->$(SET_COLOR) "
			@echo -e -n "$(GREEN)Compilação concluída$(SET_COLOR) "
			@echo -e "$(GREEN)✅$(SET_COLOR)"

clean:
		@make clean -C ./libft
		@$(RM) $(OBJ)
		@echo -e -n "$(BLUE)Arquivos objetos$(SET_COLOR)$(GREEN)  -> Excluídos$(SET_COLOR) "
		@echo -e "🗑️$(SET_COLOR)"

fclean:	clean
		@make fclean -C ./libft
		@$(RM) $(NAME)
		@echo -e -n "$(CYAN)Arquivos executáveis$(SET_COLOR)$(GREEN)  -> Excluídos$(SET_COLOR) "
		@echo -e "🗑️$(SET_COLOR)"

re:	fclean
	@echo -e -n "\n $(BG_GREEN) => Arquivos excluídos e recompilados <= $(SET_COLOR)\n"

.PHONY:	all clean fclean re