/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_redirection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:17:52 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/10 03:05:25 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_redir_list	*get_last_redirection(t_redir_list *li)
{
	t_redir_list	*tmp;

	tmp = li;
	if (li->next == NULL)
		return (NULL);
	else
		while (tmp->next != NULL)
			tmp = tmp->next;
	return (tmp);
}

void	free_redirection(t_redir_list *li)
{
	t_redir_list	*tmp;

	if (li == NULL)
		return ;
	tmp = get_last_redirection(li);
	while (tmp != NULL)
	{
		if (tmp->file_name)
			free (tmp->file_name);
		free(tmp);
		tmp = get_last_redirection(li);
	}
	if (li->file_name)
		free(li->file_name);
	free(li);
}
