# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccoto <ccoto@student.42lyon.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 15:29:29 by ccoto             #+#    #+#              #
#    Updated: 2021/04/13 10:44:56 by ccoto            ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME =		libft.a

SRCS =		ft_isalpha.c ft_memcmp.c ft_putendl_fd.c ft_strjoin.c \
			ft_strncmp.c ft_toupper.c ft_atoi.c ft_isascii.c  \
			ft_memcpy.c ft_putnbr_fd.c ft_strlcat.c ft_strnstr.c ft_bzero.c \
			ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_strlcpy.c \
			ft_strrchr.c ft_calloc.c ft_isprint.c ft_memccpy.c ft_memset.c \
			ft_strchr.c ft_strlen.c ft_substr.c ft_isalnum.c ft_itoa.c \
			ft_memchr.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c ft_tolower.c \
			ft_strtrim.c ft_split.c ft_lstlast.c  \
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
			ft_lstadd_front.c ft_lstsize.c ft_strcmp.c

OBJS = 		${SRCS:.c=.o}

CC = 		gcc

FLAGS = 	-Wall -Wextra -Werror

RM = 		rm -f

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I .

${NAME}: 	${OBJS}
		 	ar -rcs ${NAME} ${OBJS}

all: 		${NAME}

clean: 
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all

.PHONY: 	all clean fclean re
