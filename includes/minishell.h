/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:10:46 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/16 19:00:40 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../node/node.h"
# include "../signals/signals.h" 
# include "../ft_libft/libft.h"
# include "../parser/parser.h"
# include <readline/readline.h>
# include <readline/history.h>
 
struct	s_node;
struct	s_redir_list;

// typedef struct s_data
// {
// 	struct s_node 	*first_node;
// 	char			**envp;
// 	char			**path_env;
	
// }	t_data;
 
#endif