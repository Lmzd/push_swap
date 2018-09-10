# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 02:37:17 by lmazeaud          #+#    #+#              #
#    Updated: 2018/09/10 07:21:58 by lmazeaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push-swap
NAME1   = checker
CFLAGS	= -Wall -Werror -Wextra -g
CC		= gcc

LFT		= libft
INCS	= -I $(LFT)/includes -I includes
LIB		= $(INCS) -L $(LFT)/ -lft -lftprintf

SRCS_D	= srcs
SRCS_P	=	push_swap.c		\
			create_list.c	\
			check_sort.c	\
			error.c			\
			quicksort.c		\
			checker.c		\
			create_list.c 	\
			entry.c			\
			print_stack.c	\
			get_stack_params.c	\
			ft_sort_three.c	\
			push_to.c		\
			opp/push.c		\
			opp/swap.c		\
			opp/rotate.c	\
			opp/rotate_rev.c	\


OBJ_D	= 	obj
OBJ		= 	$(addprefix $(OBJ_D)/,$(SRCS:.c=.o))
OBJ_P	=	$(OBJ_D)/push_swap.o		\
			$(OBJ_D)/create_list.o	\
			$(OBJ_D)/quicksort.o	\
			$(OBJ_D)/error.o	\
			$(OBJ_D)/push_to.o	\
			$(OBJ_D)/ft_sort_three.o	\
			$(OBJ_D)/get_stack_params.o \
			$(OBJ_D)/check_sort.o	\
			$(OBJ_D)/print_stack.o	\
			$(OBJ_D)/opp/push.o		\
			$(OBJ_D)/opp/swap.o		\
			$(OBJ_D)/opp/rotate.o	\
			$(OBJ_D)/opp/rotate_rev.o	\
			

OBJ_C	=	$(OBJ_D)/checker.o		\
			$(OBJ_D)/create_list.o 	\
			$(OBJ_D)/entry.o		\
			$(OBJ_D)/get_stack_params.o \
			$(OBJ_D)/opp/push.o		\
			$(OBJ_D)/opp/swap.o		\
			$(OBJ_D)/opp/rotate.o	\
			$(OBJ_D)/opp/rotate_rev.o	\
			$(OBJ_D)/quicksort.o		\
			$(OBJ_D)/error.o		\
			$(OBJ_D)/print_stack.o	\
			$(OBJ_D)/check_sort.o	\

MD		= /bin/mkdir -p
RM		= /bin/rm -rf

all : $(NAME) $(NAME1)

create-folder : 
	@make -C $(LFT)
	@$(MD) -p $(OBJ_D)
	@$(MD) -p $(OBJ_D)/opp

$(NAME) : create-folder $(OBJ_P) 
	@$(CC) -o $@ $(OBJ_P) $(CFLAGS) $(LIB) 

$(NAME1) : $(OBJ_C)
	@$(CC) -o $@ $(OBJ_C) $(CFLAGS) $(LIB) 

$(OBJ_D)/%.o : $(SRCS_D)/%.c
	@printf "%33s %10s \n" "👉   $@" "✅ "
	@$(CC) -o $@ -c $< $(CFLAGS) $(INCS)

clean :
	@make -C $(LFT) clean 
	@$(RM) $(OBJ_D)

fclean : clean
	@make -C $(LFT) fclean
	@$(RM) $(NAME) $(NAME1)

re	: fclean all

.PHONY: clean fclean re all 

