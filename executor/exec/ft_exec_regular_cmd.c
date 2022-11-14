/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_regular_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:23:18 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/14 18:34:05 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exec_regular(t_data *data, t_node *node)
{
	if (node->cmd_exist == -1)
		exit(ft_err_cmd_exist(node));
	exit(execve(node->path_cmd, node->arg, data->envp));
}

int	ft_exec_regular_cmd(t_data *data, t_node *this_node)
{
	pid_t	child_pid;
	t_node	*node;

	node = this_node;
	if (node->is_built_in != 0)
		return (ft_call_builtin(node, data->env_var_list));
	child_pid = fork();
	if (child_pid < 0)
		return (ft_err_fork());
	else if (child_pid == 0)
		ft_exec_regular(data, node);
	ft_wait_children();
	return (0);
}
