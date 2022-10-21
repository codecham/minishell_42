/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_simple_pipe.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:34:07 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/06 12:59:13 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

int	ft_exec_simple_pipe(t_data *data, t_node *node)
{
	ft_close_bad_pipe(data->first_node, node);
	if (ft_set_fd_pipe(node) < 0)
		return (-1);
	exit(execve(node->path_cmd, node->arg, data->envp));
}