/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:26:46 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/23 20:35:38 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../includes/minishell.h"
# include "../node/node.h"
# include "../ft_libft/libft.h"
# include <stdio.h>

# define SPACE 1
# define CHAR 2
# define DOLLAR 3
# define QUOTE 4
# define DOUBLE_QUOTE 5
# define REDIRECTION 6
# define PIPE 7
# define WORDS 8
# define BAD_CHAR -1

struct	s_node;

typedef struct s_token
{
	char			*value;
	int				type;
	struct s_token	*next;
	struct s_token	*previous;
}	t_token;

typedef struct s_data_parsing
{
	struct s_token		*first_token;
	int					list_token_size;
	char				**envp;
	
}	t_data_parsing;


/* parser */
int				ft_parsing(char *input, char **envp);



/* token */
int				ft_create_token_list(t_data_parsing *data_p, char *input);
int				ft_set_char_list(t_data_parsing *data_p, char *input);
void			ft_free_token(t_token *token);
t_token			*ft_create_token(t_token *previous, t_data_parsing *p);
int				ft_cpy_in_quote(t_token *token, char *input, int i);
int				ft_set_word_token(t_data_parsing *p, t_token *token, char *input, int i);
int				ft_set_token_list(t_data_parsing *d, char *input);
int				ft_replace_env(t_data_parsing *p);
int				ft_change_env_token(t_token *token, int i, char **envp);
char			*ft_swap_env_token(t_token *token, char *value, int begin, int end);
int				ft_delete_quotes(t_data_parsing *p);
void			ft_clear_token_list(t_data_parsing *p);

/* utils */
int				ft_only_space(char *str);
int				ft_skip_space(char *str, int i);
int				ft_get_env_value(char *key, char **value, char **envp);
char 			*ft_realloc_add(char *old, char c);
int				ft_err_pars_message(t_data_parsing *data_p, char *message, int err_code);
int 			ft_err_pars_bad_char(t_data_parsing *data_p, char c, int err_code);
int				ft_is_separator(char c);
int 			ft_autorized_char(char c);
void			ft_free_dp(t_data_parsing *data_p);

/* regex */

#endif