/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:10:46 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:08:45 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../node/node.h"
# include "../signals/signals.h" 
# include "../ft_libft/libft.h"
# include "../parsing/parsing.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
 # include <dirent.h>

# define REDIRECTION 5
# define PIPE 7
# define WORDS 8
# define BAD_CHAR -1
# define ERR_MALLOC -1
# define ERROR -2

struct	s_node;
struct	s_data;
struct	s_redir_list;
struct	s_token;
struct	s_saved_fd;

int	g_exit_status;

typedef struct	s_data
{
	struct s_node	*first_node;
	struct s_token	*first_token;
	char			**envp;
	char			**path_env;
}	t_data;


typedef struct s_token
{
	char			*value;
	int				type;
	int				fd_heredoc;
	int				fd;
	char			*red_file_name;
	struct s_token	*next;
	struct s_token	*previous;
}	t_token;

typedef struct s_data_parsing
{
	struct s_token		*first_token;
	int					list_token_size;
	char				**envp;
}	t_data_parsing;


typedef struct s_redir_list
{
	int					type;		// INFILE (>) -- INFILE_HAP (>>) -- OUTFILE (<) -- HEREDOC (<<)
	int					fd;			// fd du fichier correspondant
	char				*file_name; //Nom du fichier
	struct s_redir_list	*next;		// Redirection suivante
}	t_redir_list;

typedef struct s_saved_fd
{
	int	fd_infile;		//fd du fichier in
	int	fd_outfile;		//fd du fichier out
	int fd_old_infile;	//save fdin (0)
	int	fd_old_outfile; //save fdout (1)
}	t_saved_fd;

typedef struct s_node
{
	int					is_built_in;
	char 				*command_name;	// Le nom de la commande
	char				*path_cmd;		// Chemin de la commande
	char				**arg;			// Double tableau contenant les arguments
	struct s_node		*next;			// Commande suivante aprés un pipe
	struct s_node		*previous;		// Commande précédente avant un pipe
	struct s_redir_list	*redirection;	// Liste de redirections
	struct s_saved_fd	*saved_fd;		// Les saves des fd pour les redirections
	int					pipe_in;		// fd du pipe in (init à 0)
	int					pipe_out;		// fd du pipe out (init à 1)
	int					fd_in;			// fd_in
	int					fd_out;			// fd_out
	pid_t				pid;
}	t_node;

/* parser */
int				ft_parsing(char *input, char **envp);
int				ft_free_data(t_data *data);



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
void			ft_delete_token_in_list(t_data_parsing *p, t_token *bad_token);
int 			ft_check_redir_next(t_data_parsing *p, t_token *token);
int				ft_concat_redir(t_data_parsing *p);
int				ft_ambiguous_redirect(t_data_parsing *p);
int				ft_check_syntax(t_data_parsing *p);
int 			ft_set_red_file_name(t_data_parsing *p);

/* utils */
int				ft_only_space(char *str);
int				ft_skip_space(char *str, int i);
int				ft_get_env_value(char *key, char **value, char **envp);
char 			*ft_realloc_add(char *old, char c);
int				ft_err_pars_message(t_data_parsing *data_p, char *message, int err_code);
int 			ft_err_pars_bad_char(t_data_parsing *data_p, char c, int err_code);
int				ft_err_pars_near(t_data_parsing *data_p, char *str, int err_code);
int				ft_err_pars_ambiguous(t_data_parsing *data_p, t_token *token, int err_code);
int				ft_err_pars_new_line(t_data_parsing *data_p, char *str, int err_code);
int				ft_is_separator(char c);
int 			ft_is_autorized_char(t_data_parsing *p, char *input);
int				ft_autorized_char(char c);
void			ft_free_dp(t_data_parsing *data_p);
int				ft_good_c_for_env(char c);
int				ft_is_empty_token(t_token *token);
int				ft_is_redirection(t_token *token);
int 			ft_is_directory(char *directory);

/* ast */

int				ft_set_data(t_data *data, t_data_parsing *p);
int				ft_fill_redirection(t_node *node, t_token *token);

/* heredoc */

int				ft_set_heredoc(t_data_parsing *p);
char			*ft_random_name(void);
char 			*ft_replace_env_hd(t_data_parsing *p, char *str);

/*
----------------------------------NODE-----------------------------------------
*/

t_node			*ft_create_node(void);
t_node			*ft_new_node(t_node *previous_node);
t_redir_list	*ft_get_next_redirection(t_redir_list *li);
t_redir_list 	*ft_get_last_redirection(t_redir_list *li);
int				ft_set_redirection(t_node *node, int redirect_type, int fd, char *f_name);
int				ft_add_arg_node(t_node *node, char *arg);
int				ft_add_command_name(t_node *node, char *command);
void			ft_free_nodes(t_node *node);
int				ft_has_redirection_type(t_node *node, int type);
int				ft_set_fd_pipe(t_node *node);
int				ft_has_redirection(t_node *node, int type);

#endif