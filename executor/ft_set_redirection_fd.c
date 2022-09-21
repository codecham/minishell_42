/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_redirection_fd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 05:59:42 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/21 19:03:55 by dcorenti         ###   ########.fr       */
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

void	ft_set_infile_fd(int fd)
{
	if (dup2(fd, 0) == -1)
		perror("ft_set_infile ");
}

void	ft_set_outile_fd(int fd)
{
	if (dup2(fd, 1) == -1)
		perror("ft_set_outfile:");
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
		ft_set_infile_fd(saved_fd->fd_infile);
	if (saved_fd->fd_outfile >= 0)
		ft_set_outile_fd(saved_fd->fd_outfile);
	return (saved_fd);
}