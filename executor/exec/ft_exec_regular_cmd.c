/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_regular_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:23:18 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/17 17:02:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exec_regular(t_data *data, t_node *node)
{
	exit (execve(node->path_cmd, node->arg, data->envp));
}

int	ft_good_command(t_node *node)
{
	if (node->cmd_exist == -1)
	{
		if (node->command_name == NULL && ft_has_redirection(node, 0) > -1)
			return (-1);
		g_exit_status = ft_err_cmd_exist(node);
		return (-1);
	}
	if (access(node->path_cmd, X_OK) != 0
		|| ft_strncmp(node->command_name, "./", 3) == 0)
	{
		g_exit_status = ft_err_access(node->command_name);
		return(-1);
	}
	return(0);	
}

int	ft_exec_regular_cmd(t_data *data, t_node *this_node)
{
	pid_t	child_pid;
	t_node	*node;

	node = this_node;
	if (node->is_built_in != 0)
	{
		g_exit_status = ft_call_builtin(node, data->env_var_list, data);
		return (0);
	}
	if (ft_good_command(node) == -1)
		return (0);
	ft_signal_handler_child();
	child_pid = fork();
	if (child_pid < 0)
		return (ft_err_fork());
	if (child_pid == 0)
		g_exit_status = ft_exec_regular(data, node);
	ft_wait_children();
	return (0);
}
