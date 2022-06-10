/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:15:44 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/10 03:09:24 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include <stdlib.h>
# include "../libft/libft.h"

# define COMMAND 0
# define ARG 1

# define INFILE 0
# define INFILE_HAP 1
# define OUTFILE 2
# define HEREDOC 3

struct	s_node;
struct	s_redir_list;

typedef struct s_redir_list
{
	int					type;
	char				*file_name;
	struct s_redir_list	*next;
}	t_redir_list;

typedef struct s_node
{
	int					type;
	char				*data;
	struct s_node		*first_child;
	struct s_node		*parent;
	struct s_node		*previous;
	struct s_node		*next;
	struct s_redir_list	*redirection;
}	t_node;

t_node			*create_node(void);
t_node			*get_first_child(t_node *node);
t_node			*get_next_node(t_node *node);
t_node			*get_previous_node(t_node *node);
t_node			*get_parent(t_node *node);
t_node			*get_last_node(t_node *node);
t_redir_list	*get_next_redirection(t_redir_list *li);
void			set_child(t_node *parent, char *data);
int				set_redirection(t_redir_list *li,
					int redirect_type, char *file_name);
void			free_redirection(t_redir_list *li);

#endif