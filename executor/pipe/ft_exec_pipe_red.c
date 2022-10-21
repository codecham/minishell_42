/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe_red.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:25:23 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/06 16:25:13 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

int	ft_change_fd_in(t_node *node, int new_fd)
{
	if (node->pipe_in != 0)
	{
		if (dup2(new_fd, node->pipe_in) < 0)
			return (-1);
		close(node->pipe_in);
	}
	else
	{
		if (dup2(new_fd, 0) < 0)
			return (-1);
	}
	return (0);
}

int	ft_change_fd_out(t_node *node, int new_fd)
{
	if (node->pipe_out != 0)
	{
		if (dup2(new_fd, node->pipe_out) < 0)
			return (-1);
		close(node->pipe_out);
	}
	else
	{
		if (dup2(new_fd, 1) < 0)
			return (-1);
	}
	return (0);
}

int	ft_exec_pipe_red(t_data *data, t_node *node)
{
	int file_in;
	int	file_out;

	file_in = ft_has_redirection(node, INFILE);
	file_out = ft_has_redirection(node, OUTFILE);
	if (file_in != -1)
		ft_change_fd_in(node, file_in);
	if (file_out != -1)
		ft_change_fd_out(node, file_out);
	exit(execve(node->path_cmd, node->arg, data->envp));
}