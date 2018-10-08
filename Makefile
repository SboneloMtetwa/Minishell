# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smtetwa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/01 12:43:08 by smtetwa           #+#    #+#              #
#    Updated: 2018/09/29 10:46:14 by smtetwa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

FLAGS = gcc -Wall -Wextra -Werror

SRC = exec_command.c main.c echo.c ft_environ.c setenv_b.c cd.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C libft/
	@$(FLAGS) -c $(SRC)
	@$(FLAGS) -o $(NAME) $(SRC) -L libft/ -lft

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

re: fclean all
