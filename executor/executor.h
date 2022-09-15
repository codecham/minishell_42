/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:45:33 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/15 20:29:52 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "../ft_libft/libft.h"
# include "../node/node.h"
# include <stdio.h>
# include <unistd.h>
# include <dirent.h>

char	**ft_get_path_env(char **envp);
int		ft_find_path_cmd(t_node *node, char **path_env);

#endif