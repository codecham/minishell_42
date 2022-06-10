/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 22:15:44 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/06 22:32:06 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# define COMMAND 0
# define ARG 1

# define infile 0
# define infile_hap 1
# define outfile 2
# define heredoc 3

struct s_node;
struct s_redir_list;


typedef struct s_redir_list
{
	int					type;
	char				*file_name;
	struct s_redir_list *next;
} t_redir_list;


typedef struct s_node
{
	int 				type; // COMMAND OR ARG
	char 				*data;
	struct s_node 		*first_child;
	struct s_node 		*parent;
	struct s_node 		*previous;
	struct s_node 		*next;
	struct s_redir_list *redirection;
}	t_node;

#endif