# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 15:47:13 by fvonsovs          #+#    #+#              #
#    Updated: 2023/03/31 16:43:21 by fvonsovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
NAME		=	push_swap
SRCS		=	push_swap.c list_utils.c operations_1.c test_functions.c
OBJS		=	${SRCS:.c=.o}
LIBC		=	ar -cvq
RM			=	rm -f
LIBFT		=	./libft/libft.a
.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I. -I./libft

all: $(NAME)

$(NAME): ${OBJS}
	make -C ./libft
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}

clean: 
	${MAKE} clean -C ./libft
	${RM} ${OBJS}

fclean: clean
	${MAKE} fclean -C ./libft
	${RM} ${NAME}

re: fclean all

.PHONY:	all clean fclean re
