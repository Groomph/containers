# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rsanchez <rsanchez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/19 16:05:34 by rsanchez          #+#    #+#              #
#    Updated: 2022/02/11 14:34:43 by rsanchez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

#CFLAGS = --analyze

FLAGSHARD = -Weverything

LIB	= libraries

#LIBFT	= -L $(LIB)/libft/ -lft

HEADER = includes

DIR_S = sources

DIR_O = temporary

SOURCES = main.cpp

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.cpp=.o))

all: $(NAME)

bonus: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(DIR_O)/%.o: $(DIR_S)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<

clean:
	rm -rf $(DIR_O)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re bonus norme
