/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 06:13:18 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/22 18:18:50 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# include <stdlib.h>
# include "../ft_libft/libft.h"
# include <stdio.h>
# include "../includes/minishell.h"

# define OUTFILE 0		// >
# define OUTFILE_HAP 1	// >>
# define INFILE 2		// <
# define HEREDOC 3		// <<

struct	s_node;
struct	s_redir_list;
struct	s_saved_fd;

typedef struct s_redir_list
{
	int					type;		// INFILE (>) -- INFILE_HAP (>>) -- OUTFILE (<) -- HEREDOC (<<)
	int					fd;			// fd du fichier correspondant
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


t_node			*ft_create_node(void);
t_node			*ft_new_node(t_node *previous_node);
t_redir_list	*ft_get_next_redirection(t_redir_list *li);
t_redir_list 	*ft_get_last_redirection(t_redir_list *li);
int				ft_set_redirection(t_node *node, int redirect_type, int fd);
int				ft_add_arg_node(t_node *node, char *arg);
int				ft_add_command_name(t_node *node, char *command);
void			ft_free_nodes(t_node *node);
int				ft_has_redirection_type(t_node *node, int type);
int				ft_set_fd_pipe(t_node *node);
int				ft_has_redirection(t_node *node, int type);

#endif