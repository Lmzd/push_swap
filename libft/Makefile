# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 22:33:17 by lmazeaud          #+#    #+#              #
#    Updated: 2018/08/27 02:17:28 by lmazeaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a

CC		:=	gcc

CFLAGS	:=	-Wall -Werror -Wextra

INCLUDES 	:= includes/

SRC 		:=  srcs/

LIB_PRINTF 	:= -L $(INCLUDES) -lftprintf

SOURCES 	:= 	$(shell find srcs -name '*.c' | rev | cut -d/ -f1 | rev)

SRC_FILES 	:= 	$(wildcard $(SRC)*.c)

OBJ_DIR		:=	obj/

OBJ_FILES 	:=	$(addprefix $(OBJ_DIR),$(SOURCES:.c=.o))

AR		:=	ar rc

RL		:=	ranlib

RM		:= /bin/rm -rf

LOG_CLEAR		= \033[2K
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[32m
LOG_VIOLET		= \033[1;35m

all : $(NAME)
	
$(NAME) : create-folder $(OBJ_FILES)
	@$(AR) $(NAME) $(OBJ_FILES) $(LIB_PRINTF)  
	@$(RL) $(NAME)
	@echo "$(LOG_GREEN)LIBFT CREATED SUCCESSFULLY$(LOG_NOCOLOR)"

create-folder :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC)%.c
	@$(CC) $(CFLAGS) -o $@ -c $^ -I$(INCLUDES)
	@echo "$(LOG_CLEAR)	👉  add $@	✅ $(LOG_NOCOLOR)"

norme : 
	@norminette $(SRC) $(INCLUDES)

clean:
	@$(RM) $(OBJ_DIR)
	@echo "$(LOG_CLEAR)$(LOG_RED)OBJECT FILES GO TO 🗑️$(LOG_NOCOLOR)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(LOG_RED)REMOVE $(NAME) SUCCESSFULLY 🗑️$(LOG_NOCOLOR)"
	@echo ""
	@echo ""

re : fclean all

.PHONY: create_folder all clean fclean re norme