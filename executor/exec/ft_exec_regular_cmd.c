/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_regular_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:23:18 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/09 16:19:37 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exec_regular(t_data *data, t_node *node)
{
	execve(node->path_cmd, node->arg, data->envp);
}

int	ft_exec_regular_cmd(t_data *data, t_node *this_node)
{
	pid_t	child_pid;
	t_node	*node;
	t_env	*env_var_list;

	node = this_node;
	env_var_list = ft_get_env_var_list(data->envp);
	if (node->is_built_in != 0)
	{
		/*
			code pour exec builtin
		*/
		this_node->fd_out = 1;
		ft_call_builtin(this_node, env_var_list);
	}
	else
	{
		child_pid = fork();
		if (child_pid < 0)
		{
			/*
				code pour failed fork
			*/
			return (-1);
		}
		else if (child_pid == 0)
			ft_exec_regular(data, node);
		ft_wait_children();
	}
	return (0);
}
