# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 09:48:12 by ccoto             #+#    #+#              #
#    Updated: 2021/04/15 15:29:04 by ccoto            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

PUSHSWAP = push_swap

CHECKER = checker

SRCS =	srcs/utils/errors.c srcs/utils/display.c srcs/instructions/swap.c \
		srcs/utils/utils_list.c srcs/instructions/push.c \
		srcs/instructions/rotate.c srcs/instructions/reverse.c \
		srcs/utils/utils.c srcs/utils/get_next_line.c \
		srcs/utils/get_next_line_utils.c srcs/utils/utils_sort.c \
		srcs/utils/utils_sort2.c srcs/utils/utils2.c

SRCSCHECKER  = srcs/checker.c

SRCSPUSHSWAP = srcs/push_swap.c

OBJS = ${SRCS:.c=.o}

OBJSCHECKER = ${SRCSCHECKER:.c=.o}

OBJSPUSHSWAP = ${SRCSPUSHSWAP:.c=.o}

CC = gcc 

FLAGS = -Wall -Wextra -Werror

RM = rm -f

.c.o:
					${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I .

all:				subsystem ${CHECKER} ${PUSHSWAP}

${PUSHSWAP}:	${OBJS} ${OBJSPUSHSWAP} libft/libft.a
					${CC} ${FLAGS} libft/libft.a ${OBJS} ${OBJSPUSHSWAP} -o ${PUSHSWAP}
					
${CHECKER}:	${OBJS} ${OBJSCHECKER} libft/libft.a
					${CC} ${FLAGS} libft/libft.a ${OBJS} ${OBJSCHECKER} -o ${CHECKER}

subsystem:
		make -C libft/

subclean: 
		make clean -C libft/

clean:		subclean
			${RM} ${OBJS} ${OBJSCHECKER} ${OBJSPUSHSWAP}
		
fclean: 	clean
	 		${RM} ${CHECKER} ${PUSHSWAP} libft/libft.a

re:			fclean all

.PHONY:		all clean fclean re
