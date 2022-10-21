/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_saved_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:35:30 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/06 12:28:05 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

/*
	La fonction ft_reset_saved_fd va restaurer les fd 0 et 1 sur
	STDIN ET STDOUT

	PARAMETRE: La structure contenant les fd à modifier
*/

void 	ft_reset_saved_fd(t_node *node)
{
	if (!node->saved_fd)
		return ;
	if (node->saved_fd->fd_infile > 0)
	{
		if (dup2(node->saved_fd->fd_old_infile, 0) == -1)
			perror("ft_reset_node->saved_fd_infile ");
	}
	if (node->saved_fd->fd_outfile > 0)
	{
		if (dup2(node->saved_fd->fd_old_outfile, 1) == -1)
			perror("ft_reset_node->saved_fd_out ");
	}
}