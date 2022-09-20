/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_regular_cmd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:23:18 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/20 17:50:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	ft_exec_regular(t_data *data, t_node *node)
{
	if (execve(node->path_cmd, node->arg, data->envp) == -1)
		printf("execve failed\n");
}

int	ft_exec_regular_cmd(t_data *data)
{
	pid_t	child_pid;
	t_node	*node;

	node = data->first_node;
	if (node->is_built_in != 0)
	{
		/*
			code pour exec builtin
		*/
		printf("%s is a builtin...\n", node->command_name);
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