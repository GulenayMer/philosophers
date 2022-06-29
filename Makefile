# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgulenay <mgulenay@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 17:42:11 by mgulenay          #+#    #+#              #
#    Updated: 2022/06/29 19:49:48 by mgulenay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	philo

CC 		= 	gcc

CFLAGS 	= 	-Wall -Wextra -Werror -g

SRCS 	=	main.c \
			utils.c \
			init.c \
			error_check.c \
			actions.c \
			
SRC_OBJS	=	$(SRCS:%.c=%.o)

RM          =	rm -f

$(NAME): $(SRC_OBJS)
	$(CC) $(CFLAGS) -g -lpthread -fsanitize=thread -o $(NAME) $(SRC_OBJS) 

all : $(NAME)

clean:
		$(RM) $(SRC_OBJS)

fclean:		clean
				$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re