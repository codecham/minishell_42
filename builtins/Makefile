NAME	= builtin

CFLAGS	= -Wall -Wextra -Werror
CC		= gcc

LIBFT_D	= ../ft_libft
LIBFT	= ../ft_libft/libft.a

SRC		= main.c \
		ft_builtins.c \
		ft_echo.c \
		ft_cd.c \
		ft_pwd.c \
		ft_unset.c \
		ft_env.c \
		ft_exit.c \
		env/ft_create_env_var_list.c \
		env/ft_cpy_env_var.c \
		env/ft_free_env_var.c \
		env/ft_new_env_var.c \
		../node/ft_add_arg_node.c ../node/ft_add_command_name.c \
		../node/ft_count_node.c ../node/ft_create_node.c \
		../node/ft_free_nodes.c ../node/ft_get_last_redirection.c \
		../node/ft_get_next_redirection.c ../node/ft_has_redirection_type.c \
		../node/ft_new_node.c ../node/ft_set_redirection.c

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
