/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_simple_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:34:07 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/14 17:54:42 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exec_simple_pipe(t_data *data, t_node *node)
{
	ft_close_bad_pipe(data->first_node, node);
	if (ft_set_fd_pipe(node) < 0)
		return (-1);
	if (node->cmd_exist == -1)
		exit(ft_err_cmd_exist(node));
	if (node->is_built_in != 0)
		exit(ft_call_builtin(node, data->env_var_list));
	exit (execve(node->path_cmd, node->arg, data->envp));
}
