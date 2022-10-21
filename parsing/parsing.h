/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:26:46 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/21 15:38:46 by dcorenti         ###   ########.fr       */
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
	char				**envp;
	
}	t_data_parsing;

int				ft_only_space(char *str);
int				ft_skip_space(char *str, int i);
int				ft_parsing(char *input, char **envp);
int				ft_set_char_list(t_data_parsing *data_p, char *input);
void			ft_free_token(t_token *token);
t_token			*ft_create_token(t_token *previous);
int				ft_get_env_value(char *key, char **value, char **envp);
int				ft_err_pars(t_data_parsing *data_p);
char 			*ft_realloc_add(char *old, char c);
int				ft_cpy_in_quote(t_token *token, char *input, int i);
int				ft_err_pars_message(t_data_parsing *data_p, char *message);
int				ft_set_word_token(t_data_parsing *d, t_token *token, char *input, int i);
int				ft_is_separator(char c);
int 			ft_autorized_char(char c);
int				ft_err_pars_bad_char(t_data_parsing *data_p, char c);
int				ft_set_token_list(t_data_parsing *d, char *input);
void			ft_free_dp(t_data_parsing *data_p);
int				ft_replace_env(t_data_parsing *p);
int				ft_change_env_token(t_token *token, int i, char **envp);
char			*ft_swap_env_token(char *str, char *value, int begin, int end);
int				ft_delete_quotes(t_data_parsing *p);

#endif