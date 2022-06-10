/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:28:23 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/10 03:06:13 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

int	set_redirection(t_redir_list *li, int redirect_type, char *file_name)
{
	t_redir_list	*redirection;

	redirection = (t_redir_list *)malloc(sizeof(t_redir_list));
	if (!redirection)
		return (-1);
	redirection->file_name = ft_strdup(file_name);
	redirection->type = redirect_type;
	redirection->next = NULL;
	if (li == NULL)
		li = redirection;
	else
	{
		while (li->next != NULL)
			li = li->next;
		li->next = redirection;
	}
	return (0);
}
