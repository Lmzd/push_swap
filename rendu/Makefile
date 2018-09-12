# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 02:37:17 by lmazeaud          #+#    #+#              #
#    Updated: 2018/09/12 22:55:01 by lmazeaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap
NAME1   = checker
CFLAGS	= -Wall -Werror -Wextra -g
CC		= gcc

LFT		= libft
INCS	= -I $(LFT)/includes -I includes
LIB		= $(INCS) -L $(LFT)/ -lft -lftprintf

SRCS_D	= srcs
SRCS_P	=	error.c	\
			entry.c	\
			helper.c	\
			checker.c	\
			opp/swap.c	\
			opp/push.c	\
			push_swap.c	\
			quicksort.c	\
			push_to_a.c	\
			push_to_b.c	\
			free_list.c	\
			opp/rotate.c	\
			check_sort.c	\
			create_list.c	\
			create_list.c 	\
			print_stack.c	\
			get_arg_push.c	\
			ft_sort_three.c	\
			opp/rotate_rev.c	\
			get_arg_checker.c	\
			get_stack_params.c	\


OBJ_D	= 	obj
OBJ		= 	$(addprefix $(OBJ_D)/,$(SRCS:.c=.o))

OBJ_P	=	$(OBJ_D)/error.o	\
			$(OBJ_D)/helper.o	\
			$(OBJ_D)/opp/push.o	\
			$(OBJ_D)/opp/swap.o	\
			$(OBJ_D)/push_swap.o	\
			$(OBJ_D)/push_to_a.o	\
			$(OBJ_D)/push_to_b.o	\
			$(OBJ_D)/free_list.o	\
			$(OBJ_D)/quicksort.o	\
			$(OBJ_D)/check_sort.o	\
			$(OBJ_D)/opp/rotate.o	\
			$(OBJ_D)/print_stack.o	\
			$(OBJ_D)/create_list.o	\
			$(OBJ_D)/get_arg_push.o	\
			$(OBJ_D)/ft_sort_three.o	\
			$(OBJ_D)/opp/rotate_rev.o	\
			$(OBJ_D)/get_stack_params.o \
			

OBJ_C	=	$(OBJ_D)/entry.o	\
			$(OBJ_D)/error.o	\
			$(OBJ_D)/helper.o	\
			$(OBJ_D)/checker.o	\
			$(OBJ_D)/opp/push.o	\
			$(OBJ_D)/opp/swap.o	\
			$(OBJ_D)/quicksort.o	\
			$(OBJ_D)/free_list.o	\
			$(OBJ_D)/check_sort.o	\
			$(OBJ_D)/opp/rotate.o	\
			$(OBJ_D)/print_stack.o	\
			$(OBJ_D)/create_list.o 	\
			$(OBJ_D)/opp/rotate_rev.o	\
			$(OBJ_D)/get_arg_checker.o	\
			$(OBJ_D)/get_stack_params.o \


LOG_CLEAR		= \033[2K
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[32m
LOG_VIOLET		= \033[1;35m

MD		= /bin/mkdir -p
RM		= /bin/rm -rf

all : $(NAME) $(NAME1)

$(NAME) : $(OBJ_P) 
	@make -C $(LFT)
	@$(CC) -o $@ $(OBJ_P) $(CFLAGS) $(LIB) 
	@echo "$(LOG_VIOLET)PUSH_SWAP CREATED SUCCESSFULLY$(LOG_NOCOLOR)"

$(NAME1) : $(OBJ_C)
	@$(CC) -o $@ $(OBJ_C) $(CFLAGS) $(LIB)
	@echo "$(LOG_VIOLET)CHECKER CREATED SUCCESSFULLY$(LOG_NOCOLOR)"

$(OBJ_D)/%.o : $(SRCS_D)/%.c
	@$(MD) -p $(OBJ_D)
	@$(MD) -p $(OBJ_D)/opp
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

