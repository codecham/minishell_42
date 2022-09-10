/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 06:13:18 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/10 17:49:58 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

#include <stdlib.h>

# define INFILE 0
# define INFILE_HAP 1
# define OUTFILE 2
# define HEREDOC 3

struct	s_node;
struct	s_redir_list;

typedef struct s_redir_list
{
	int					type;		// INFILE (>) -- INFILE_HAP (>>) -- OUTFILE (<) -- HEREDOC (<<)
	int					fd;			// fd du fichier correspondant
	struct s_redir_list	*next;		// Redirection suivante
}	t_redir_list;

typedef struct s_node
{
	char 				*command_name;	// Le nom de la commande
	char				**arg;			// Double tableau contenant les arguments
	char				**env;			// Double tableau contenant la listes des variables d'environement
	struct s_node		*next;			// Commande suivante aprés un pipe
	struct s_node		*previous;		// Commande précédente avant un pipe
	struct s_redir_list	*redirection;	// Liste de redirections
}	t_node;


t_node			*ft_create_node(void);
t_node			*ft_new_node(t_node *previous_node);
int				set_redirection(t_node *node, int redirect_type, int fd);
t_redir_list	*ft_get_next_redirection(t_redir_list *li);

#endif