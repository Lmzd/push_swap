# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 02:37:17 by lmazeaud          #+#    #+#              #
#    Updated: 2018/08/30 18:29:13 by lmazeaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push-swap
CFLAGS	= -Wall -Werror -Wextra -g
CC		= gcc

LFT		= libft
INCS	= -I $(LFT)/includes -I includes
LIB		= $(INCS) -L $(LFT)/ -lft -lftprintf

SRCS_D	= srcs
SRCS	=	push_swap.c		\
			create_list.c

OBJ_D	= obj
OBJ		= $(addprefix $(OBJ_D)/,$(SRCS:.c=.o))

MD		= /bin/mkdir -p
RM		= /bin/rm -rf

all : $(NAME)

create-folder : 
	@make -C $(LFT)
	@$(MD) $(OBJ_D)

$(NAME) : create-folder $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) $(LIB)  

$(OBJ_D)/%.o : $(SRCS_D)/%.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean :
	@make -C $(LFT) clean 
	@$(RM) $(OBJ_D)

fclean :
	@make -C $(LFT) fclean
	@$(RM) $(NAME)

re	: fclean all

.PHONY: clean fclean re all 

