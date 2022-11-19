/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_redirection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 06:08:47 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:01:42 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_search_infile_redir(t_redir_list *elem)
{
	t_redir_list	*tmp;
	int				fd;

	if (!elem)
		return (-2);
	tmp = elem;
	fd = -1;
	while (1)
	{
		if (tmp->type == INFILE || tmp->type == HEREDOC)
			fd = tmp->fd;
		if (tmp->next == NULL)
			break ;
		tmp = elem->next;
	}
	return (fd);
}

int	ft_search_outfile_redir(t_redir_list *elem)
{
	t_redir_list	*tmp;
	int				fd;

	if (!elem)
		return (-2);
	tmp = elem;
	fd = -1;
	while (1)
	{
		if (tmp->type == OUTFILE || tmp->type == OUTFILE_HAP)
			fd = tmp->fd;
		if (tmp->next == NULL)
			break ;
		tmp = elem->next;
	}
	return (fd);
}
