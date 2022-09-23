SHELL	= /bin/bash

NAME	= libft.a
INCS	= include/
SRC_DIR	= source/
OBJ_DIR	= obj/
RM		= rm -f
AR		= ar rcs
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I

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

LIBFT_DIR	= lib/
LIBFT		= ft_atoi ft_bzero ft_calloc ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_itoa ft_memchr ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper ft_utoa ft_lstnew_bonus ft_lstadd_front_bonus ft_lstsize_bonus ft_lstlast_bonus ft_lstadd_back_bonus ft_lstdelone_bonus ft_lstclear_bonus ft_lstiter_bonus ft_lstmap_bonus

GNL_DIR		= get_next_line/
GNL			= get_next_line get_next_line_utils

FTPRINTF_DIR	= ft_printf/
FTPRINTF		= ft_printf ft_printf_utils ft_printf_hexa ft_printf_ptr

SRC_FILES+=$(addprefix $(LIBFT_DIR),$(LIBFT))
SRC_FILES+=$(addprefix $(GNL_DIR),$(GNL))
SRC_FILES+=$(addprefix $(FTPRINTF_DIR),$(FTPRINTF))

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

###

OBJF		= .cache_exists

start:
			@echo -e -n "🖥️$(SET_COLOR)  "
			@echo -e -n "$(L_CYAN)LIBFT:$(SET_COLOR) "
			@echo -e -n "$(WHITE)[$(SET_COLOR)"
			@make all

all:	$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo -e -n "$(WHITE)]$(SET_COLOR)"
			@echo -e -n " $(L_GREEN)->$(SET_COLOR)"
			@echo -e -n "$(L_GREEN) Completed$(SET_COLOR)"
			@echo -e "$(GREEN) ✅$(SET_COLOR)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | ${OBJF}
			@echo -e -n "$(L_GREEN)✓$(SET_COLOR)"
			@$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)
			@mkdir -p $(OBJ_DIR)$(LIBFT_DIR)
			@mkdir -p $(OBJ_DIR)$(GNL_DIR)
			@mkdir -p $(OBJ_DIR)$(FTPRINTF_DIR)
			@touch $(OBJF)

clean:
		@$(RM) -r $(OBJ_DIR)
		@$(RM) $(OBJF)
		@echo -e -n "$(MAGENTA)[LIBFT]:$(SET_COLOR)$(BLUE) Object files$(SET_COLOR)$(GREEN)  => Cleaned$(SET_COLOR)"
		@echo -e "$(GREEN)🗑️$(SET_COLOR)"

fclean:	clean	
		@$(RM) $(NAME)
		@echo -e -n "$(MAGENTA)[LIBFT]:$(SET_COLOR)$(BLUE) Object files$(SET_COLOR)$(GREEN)  => Cleaned$(SET_COLOR)"
		@echo -e "$(GREEN)🗑️$(SET_COLOR)"

re:	fclean start
	@echo -e "\n$(BG_GREEN) => Cleaned and rebuilt everything <= $(SET_COLOR)"

.PHONY:	all bonus clean fclean re
