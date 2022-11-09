# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 23:36:50 by dcorenti          #+#    #+#              #
#    Updated: 2022/11/09 23:54:56 by dcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell

CFLAGS	= -Wall -Wextra -Werror
CC		= gcc

LIBFT_D	= ft_libft
LIBFT	= ft_libft/libft.a

SRC		= 	minishell.c \
			parsing/ast/ft_set_data.c \
			parsing/ast/ft_fill_redirection.c \
			parsing/heredoc/ft_create_heredoc.c \
			parsing/heredoc/ft_random_name.c \
			parsing/heredoc/ft_replace_env_hd.c \
			parsing/parser/ft_free_data.c \
			parsing/parser/ft_parsing.c \
			parsing/token/ft_ambiguous_redirect.c \
			parsing/token/ft_change_env_token.c \
			parsing/token/ft_check_redir_next.c \
			parsing/token/ft_check_syntax.c \
			parsing/token/ft_concat_redir.c \
			parsing/token/ft_cpy_in_quote.c \
			parsing/token/ft_create_token.c \
			parsing/token/ft_create_token_list.c \
			parsing/token/ft_delete_quotes.c \
			parsing/token/ft_delete_token_in_list.c \
			parsing/token/ft_free_token.c \
			parsing/token/ft_replace_env.c \
			parsing/token/ft_set_red_file_name.c \
			parsing/token/ft_set_token_list.c \
			parsing/token/ft_set_word_token.c \
			parsing/token/ft_swap_env_token.c \
			parsing/utils/ft_autorized_char.c \
			parsing/utils/ft_err_pars.c \
			parsing/utils/ft_free_dp.c \
			parsing/utils/ft_get_env_value.c \
			parsing/utils/ft_good_c_for_env.c \
			parsing/utils/ft_is_empty_token.c \
			parsing/utils/ft_is_redirection.c \
			parsing/utils/ft_is_separator.c \
			parsing/utils/ft_only_space.c \
			parsing/utils/ft_realloc_add.c \
			parsing/utils/ft_skip_space.c \
			node/ft_add_arg_node.c \
			node/ft_add_command_name.c \
			node/ft_count_node.c \
			node/ft_create_node.c \
			node/ft_free_nodes.c \
			node/ft_get_last_redirection.c \
			node/ft_get_next_redirection.c \
			node/ft_has_redirection_type.c \
			node/ft_new_node.c \
			node/ft_set_redirection.c \
			executor/exec/ft_exec_regular_cmd.c \
			executor/exec/ft_executor.c \
			executor/exec/ft_set_path_cmd.c \
			executor/redirection/ft_search_redirection.c \
			executor/redirection/ft_set_redirection_fd.c \
			executor/utils/ft_err_exec.c \
			executor/utils/ft_find_path_cmd.c \
			executor/utils/ft_get_env_by_key.c \
			executor/utils/ft_get_path_env.c \
			executor/utils/ft_is_builtin.c \
			executor/utils/ft_is_directory.c \
			executor/utils/ft_open_files.c \
			executor/utils/ft_reset_saved_fd.c \
			executor/utils/ft_save_in_out.c \
			executor/utils/ft_wait_children.c \

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
