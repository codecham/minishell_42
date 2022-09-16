/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:45:33 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/16 20:13:25 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../includes/minishell.h"
# include "../ft_libft/libft.h"
# include "../node/node.h"
# include "../parser/parser.h"
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>

# define ECHO 1
# define CD 2
# define PWD 3
# define EXPORT 4
# define UNSET 5
# define ENV 6
# define EXIT 7

void	ft_executor(t_data *data);
char	**ft_get_path_env(char **envp);
int		ft_find_path_cmd(t_node *node, char **path_env);
void	ft_is_builtin(t_node *node);
int		ft_relative_path(t_data *data);

#endif