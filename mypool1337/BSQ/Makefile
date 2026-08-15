# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamossai <hamossai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/04 20:52:52 by hamossai          #+#    #+#              #
#    Updated: 2026/08/15 18:23:31 by hamossai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= bsq
SRC	= $(wildcard srcs/*c)
OBJ	= $(SRC:.c=.o)
CC	= cc
FLAGS	= -Wall -Wextra -Werror
INCD	= -I includes
RM	= rm -f

all: $(NAME)
$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
%.o: %.c
	@$(CC) $(FLAGS) $(INCD) -c $< -o $@
clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
