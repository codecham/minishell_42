/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:27:21 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/09 16:20:08 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_has_redirection(t_node *node, int type)
{
	t_redir_list *elem;
	int	fd;
	
	fd = -1;
	elem = node->redirection;
	if (type == INFILE)
	{
		while (1)
		{
			if (elem->type == INFILE || elem->type == HEREDOC)
				fd = elem->fd;
			if (elem->next == NULL)
				break ;
			elem = elem->next;
		}
	}
	else if (type == OUTFILE)
	{
		while (1)
		{
			if (elem->type == OUTFILE || elem->type == OUTFILE_HAP)
				fd = elem->fd;
			if (elem->next == NULL)
				break ;
			elem = elem->next;
		}
	}
	return (fd);
}
