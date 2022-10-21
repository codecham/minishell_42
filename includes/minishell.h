/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:10:46 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/14 11:14:05 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../node/node.h"
# include "../signals/signals.h" 
# include "../ft_libft/libft.h"
# include "../parsing/parsing.h"
// # include "../executor/executor.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
 
struct	s_node;
struct	s_redir_list;
struct	s_data;

int	g_exit_status;

typedef struct	s_data
{
	struct s_node	*first_node;
	char			**envp;
	char			**path_env;

}	t_data;
 
#endif