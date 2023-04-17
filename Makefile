# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 15:47:13 by fvonsovs          #+#    #+#              #
#    Updated: 2023/04/17 17:38:05 by fvonsovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=address
NAME		=	push_swap
SRCS		=	main.c push_swap.c input_check.c list_utils_1.c list_utils_2.c \
				operations_1.c operations_2.c sort_3_5.c sort_lots.c 
OBJS		=	${SRCS:.c=.o}
BONUS_NAME	=	checker
BONUS		=	bonus_checker.c
BONUS_OBJS	=	$(BONUS:.c=.o)
LIBC		=	ar -cq
RM			=	rm -f
LIBFT		=	./libft/libft.a

# Colors
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RESET		=	\033[0m

.c.o:
	@echo "${YELLOW}Compiling: ${GREEN}$<${RESET}"
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I. -I./libft

all: $(NAME)

$(NAME): ${OBJS}
	@echo "${YELLOW}Compiling libft...${RESET}"
	@make -C ./libft
	@echo "${YELLOW}Linking objects...${RESET}"
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT}
	@echo "${GREEN}Compilation successful.${RESET}"

BONUS_OBJS_MAINLESS = $(filter-out main.o, ${OBJS})

$(BONUS_NAME): ${BONUS_OBJS} ${BONUS_OBJS_MAINLESS}
	@echo "${YELLOW}Linking objects...${RESET}"
	@${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} ${BONUS_OBJS_MAINLESS} ${LIBFT}

bonus: ${BONUS_NAME}
	@echo "${YELLOW}Compiling bonus...${RESET}"
	@${MAKE} $(BONUS_NAME)
	@echo "${GREEN}Compilation successful.${RESET}"

clean: 
	@echo "${YELLOW}Cleaning libft...${RESET}"
	@${MAKE} clean -C ./libft
	@echo "${YELLOW}Removing object files...${RESET}"
	@${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	@echo "${YELLOW}Cleaning libft...${RESET}"
	@${MAKE} fclean -C ./libft
	@echo "${YELLOW}Removing executable...${RESET}"
	@${RM} ${NAME} ${BONUS_NAME}

re: fclean all

.PHONY:	all clean fclean re
