# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 08:52:37 by jpaterno          #+#    #+#              #
#    Updated: 2022/09/14 08:52:40 by jpaterno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##### Makefile de clodo

NAME = minishell

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -lreadline */*.c -o ${NAME}

#clean:
#	rm */*.o

fclean:
	rm ${NAME}


re: fclean all

.PHONY: clean fclean all re