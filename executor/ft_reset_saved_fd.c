/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_saved_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:35:30 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/22 06:31:23 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*
	La fonction ft_reset_saved_fd va restaurer les fd 0 et 1 sur
	STDIN ET STDOUT

	PARAMETRE: La structure contenant les fd à modifier
*/

void 	ft_reset_saved_fd(t_saved_fd *saved_fd)
{
	if (!saved_fd)
		return ;
	if (saved_fd->fd_infile > 0)
	{
		if (dup2(saved_fd->fd_old_infile, 0) == -1)
			perror("ft_reset_saved_fd_infile ");
	}
	if (saved_fd->fd_outfile > 0)
	{
		if (dup2(saved_fd->fd_old_outfile, 1) == -1)
			perror("ft_reset_saved_fd_out ");
	}
}