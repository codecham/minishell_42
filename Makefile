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

NAME	= minishell

CFLAGS	= -Wall -Wextra -Werror
CC		= gcc

LIBFT_D	= ft_libft
LIBFT	= ft_libft/libft.a

SRC		= minishell.c \
		parsing/parser/ft_parsing.c parsing/parser/set_data.c \
		parsing/regex/ft_check_token.c \
		parsing/token/ft_change_env_token.c parsing/token/ft_free_token.c \
		parsing/token/ft_clear_token_list.c parsing/token/ft_replace_env.c \
		parsing/token/ft_cpy_in_quote.c parsing/token/ft_set_token_list.c \
		parsing/token/ft_create_token.c parsing/token/ft_set_word_token.c \
		parsing/token/ft_create_token_list.c parsing/token/ft_swap_env_token.c \
		parsing/token/ft_delete_quotes.c \
		parsing/utils/ft_autorized_char.c parsing/utils/ft_is_separator.c \
		parsing/utils/ft_err_pars.c parsing/utils/ft_only_space.c \
		parsing/utils/ft_free_dp.c parsing/utils/ft_realloc_add.c \
		parsing/utils/ft_get_env_value.c parsing/utils/ft_skip_space.c \
		node/ft_add_arg_node.c node/ft_add_command_name.c \
		node/ft_count_node.c node/ft_create_node.c \
		node/ft_free_nodes.c node/ft_get_last_redirection.c \
		node/ft_get_next_redirection.c node/ft_has_redirection_type.c \
		node/ft_new_node.c node/ft_set_redirection.c \


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ $(MAKE) -C $(LIBFT_D) all
	@ $(CC) ${CFLAGS} -o $(NAME) $(OBJ) $(LIBFT) -lreadline

clean:
	@ $(MAKE) -C $(LIBFT_D) clean
	@ rm -f $(OBJ)

fclean: clean
	rm -f ${NAME}
	@ $(MAKE) -C $(LIBFT_D) fclean


re: fclean all

.PHONY: clean fclean all re
