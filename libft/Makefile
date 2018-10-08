# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/07 13:33:37 by smtetwa           #+#    #+#              #
#    Updated: 2018/06/09 14:00:52 by smtetwa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

INCLUDE		=./libft.h

SRC			= ./*.c

OBJ			= ./*.o

all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRC)
	gcc -Wall -Werror -Wextra -c -I$(INCLUDE) $(SRC)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
