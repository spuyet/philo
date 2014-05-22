# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbacoux <mbacoux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/05/09 20:18:01 by mbacoux           #+#    #+#              #
#    Updated: 2014/05/09 20:27:49 by mbacoux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME := philo
CFLAGS := -Wall -Wextra -Werror
LFLAGS := -L /opt/X11/lib -lX11 -lGL -lGLU
FILES := error.c		\
		 exit.c			\
		 game.c			\
		 main.c			\
		 math.c			\
		 mem.c			\
		 neighboor.c	\
		 philo.c		\
		 render.c		\
		 simulate.c		\
		 window.c
SRC := $(addprefix src/, $(FILES))
OBJ := $(SRC:src/%.c=obj/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LFLAGS) $(OBJ) -o $@

obj/%.o: src/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -I include -I /opt/X11/include -c $< -o $@

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all


