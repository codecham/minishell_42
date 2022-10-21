/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_redirection_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 05:59:42 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/06 12:29:12 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

/*
	Fonction qui va set les fd des redirection.
	Elle va changer le fd de STDIN et/ou STDOUT

	PARAMETRE: La node de la commande à modifier les redirection.

	RETURN: Renvoie 0
*/

int	ft_set_infile_fd(int new_fd, int fd_in)
{
	int	old_fd;

	old_fd = dup(fd_in);
	if (dup2(new_fd, fd_in) == -1)
		perror("ft_set_infile ");
	return (old_fd);
}

int	ft_set_outile_fd(int new_fd, int fd_out)
{
	int	old_fd;

	old_fd = dup(fd_out);
	if (dup2(new_fd, fd_out) == -1)
		perror("ft_set_outfile:");
	return (old_fd);
}

int	ft_set_redirection_fd(t_node *node)
{
	int	fd_old_infile;
	int	fd_old_outfile;
	
	node->saved_fd->fd_infile = ft_search_infile_redir(node->redirection);
	node->saved_fd->fd_outfile = ft_search_outfile_redir(node->redirection);
	if (node->saved_fd->fd_infile >= 0)
		fd_old_infile = ft_set_infile_fd(node->saved_fd->fd_infile,
				node->fd_in);
	if (node->saved_fd->fd_outfile >= 0)
		fd_old_outfile = ft_set_outile_fd(node->saved_fd->fd_outfile,
				node->fd_out);
	if (node->pipe_in <= 0)
		node->saved_fd->fd_old_infile = fd_old_infile;
	if (node->pipe_out <= 0)
		node->saved_fd->fd_old_outfile = fd_old_outfile;
	return (0);
}
