/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe_red.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:25:23 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/16 06:50:56 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exec_pipe_red(t_data *data, t_node *node)
{
	if (node->cmd_exist == -1)
		exit(ft_err_cmd_exist(node));
	if (node->is_built_in != 0)
		exit(ft_call_builtin(node, data->env_var_list, data));
	if (access(node->path_cmd, X_OK) != 0
		|| ft_strncmp(node->command_name, "./", 3) == 0)
		exit(ft_err_access(node->command_name));
	exit (execve(node->path_cmd, node->arg, data->envp));
}
