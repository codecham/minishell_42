/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_redirection_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 05:59:42 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/28 21:15:26 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*
	Fonction qui va set les fd des redirection.
	Elle va changer le fd de STDIN et/ou STDOUT

	PARAMETRE: La node de la commande à modifier les redirection.

	RETURN: Renvoie une structure contenant la savegarde des fd modifier
	pour pourvoir les restaurer par la suite.
*/

int	ft_set_infile_fd(int new_fd, int fd_in)
{
	int	old_fd;

	old_fd = dup(0);
	if (dup2(new_fd, fd_in) == -1)
		perror("ft_set_infile ");
	return (old_fd);
}

int	ft_set_outile_fd(int new_fd, int fd_out)
{
	int	old_fd;

	old_fd = dup(1);
	if (dup2(new_fd, fd_out) == -1)
		perror("ft_set_outfile:");
	return (old_fd);
}

t_saved_fd	*ft_set_redirection_fd(t_node *node)
{
	t_saved_fd	*saved_fd;

	saved_fd = malloc(sizeof(t_saved_fd));
	if (!saved_fd)
		return (NULL);
	saved_fd->fd_infile = ft_search_infile_redir(node->redirection);
	saved_fd->fd_outfile = ft_search_outfile_redir(node->redirection);
	if (saved_fd->fd_infile >= 0)
		saved_fd->fd_old_infile = ft_set_infile_fd(saved_fd->fd_infile,
				node->fd_in);
	if (saved_fd->fd_outfile >= 0)
		saved_fd->fd_old_outfile = ft_set_outile_fd(saved_fd->fd_outfile,
				node->fd_out);
	return (saved_fd);
}
