/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fd_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:48:48 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/09 16:20:15 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	ft_set_pipe va set les fd sur le d'entrêe et/ou de sortie

*/

int	ft_set_fd_pipe(t_node *node)
{
	if (node->pipe_in != 0)
	{
		if ((node->saved_fd->fd_old_infile = dup(0)) < 0)
			perror("1");
		if (dup2(node->pipe_in, 0) < 0)
			perror("2");
	}
	if (node->pipe_out != 0)
	{
		if ((node->saved_fd->fd_old_outfile = dup(1)) < 0)
			perror("3");
		if (dup2(node->pipe_out, 1) < 0)
			perror("4");
	}
	return (0); 
}