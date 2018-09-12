# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmazeaud <lmazeaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 22:33:17 by lmazeaud          #+#    #+#              #
#    Updated: 2018/09/12 22:52:55 by lmazeaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a
CC		:=	gcc
CFLAGS	:=	-Wall -Werror -Wextra -g

INCLUDES 	:= includes

SRCS_D		:=  srcs
SRCS 		:= 	ft_abs_intmax.c			\
				ft_atoi.c				\
				ft_bzero.c				\
				ft_cutstr.c				\
				ft_fillit.c				\
				ft_freetabstr.c			\
				ft_isalnum.c			\
				ft_isalpha.c			\
				ft_isascii.c			\
				ft_isblanks.c			\
				ft_isdigit.c			\
				ft_islower.c			\
				ft_isprint.c			\
				ft_isupper.c			\
				ft_itoa_base_intmax.c	\
				ft_itoa_base_uintmax.c	\
				ft_itoa_base_intmax.c	\
				ft_itoa_intmax.c		\
				ft_itoa.c				\
				ft_lstadd.c				\
				ft_lstdel.c				\
				ft_lstdelone.c			\
				ft_lstiter.c			\
				ft_lstmap.c				\
				ft_lstnew.c				\
				ft_memalloc.c			\
				ft_memccpy.c			\
				ft_memchr.c				\
				ft_memcmp.c				\
				ft_memdel.c				\
				ft_memmove.c			\
				ft_memset.c				\
				ft_printnum_arr.c		\
				ft_printnum_lst.c		\
				ft_printstr_arr.c		\
				ft_printstr_lst.c		\
				ft_putnbr.c				\
				ft_putchar_fd.c			\
				ft_putchar.c			\
				ft_putendl_fd.c			\
				ft_putendl.c			\
				ft_putstr_fd.c			\
				ft_putstr.c				\
				ft_putwchar.c			\
				ft_sqrt.c				\
				ft_str_is_number.c		\
				ft_strcat.c				\
				ft_strchr.c				\
				ft_strclr.c				\
				ft_strcmp.c				\
				ft_strcpy.c				\
				ft_strcut.c				\
				ft_strdel.c				\
				ft_strdup.c				\
				ft_strequ.c				\
				ft_strhas_char.c		\
				ft_strhas_digit.c		\
				ft_strhas_str.c			\
				ft_strhaszero.c			\
				ft_striter.c			\
				ft_striteri.c			\
				ft_strjoin.c			\
				ft_strlcat.c			\
				ft_strlen.c				\
				ft_strmap.c				\
				ft_strmapi.c			\
				ft_strncat.c			\
				ft_strncmp.c			\
				ft_strncpy.c			\
				ft_strncut.c			\
				ft_strndup.c			\
				ft_strnequ.c			\
				ft_strnew.c				\
				ft_strnstr.c			\
				ft_strrchr.c			\
				ft_strreplace.c			\
				ft_strsplit.c			\
				ft_strstr.c				\
				ft_strsub.c				\
				ft_strtoupper.c			\
				ft_strtrim.c			\
				ft_strwlen.c			\
				ft_tolower.c			\
				ft_toupper.c			\
				ft_wbzero.c				\
				ft_wcharlen.c			\
				ft_word_count.c			\
				get_next_line.c


OBJ_D		:=	obj
OBJ 	:=	$(addprefix $(OBJ_D)/,$(SRCS:.c=.o))

AR		:=	ar rc
RL		:=	ranlib

RM		:= /bin/rm -rf

LOG_CLEAR		= \033[2K
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[32m
LOG_VIOLET		= \033[1;35m

all :  $(NAME)
	
$(NAME) : $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@$(RL) $(NAME)
	@echo "$(LOG_GREEN)LIBFT CREATED SUCCESSFULLY$(LOG_NOCOLOR)"

$(OBJ_D)/%.o : $(SRCS_D)/%.c
	@mkdir -p $(OBJ_D)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INCLUDES)
	@printf "%33s %10s \n" "👉   $@" "✅ " 

norme : 
	@norminette $(SRC) $(INCLUDES)

clean:
	@$(RM) $(OBJ_D)
	@echo "$(LOG_CLEAR)$(LOG_RED)OBJECT FILES GO TO 🗑️$(LOG_NOCOLOR)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(LOG_RED)REMOVE $(NAME) SUCCESSFULLY 🗑️$(LOG_NOCOLOR)"
	@echo ""
	@echo ""

re : fclean all

.PHONY: all clean fclean re norme