/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:07:17 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:08:04 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*ft_create_token(t_token *previous, t_data_parsing *p)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->value = NULL;
	new->type = -1;
	new->fd_heredoc = -1;
	new->fd = -1;
	new->next = NULL;
	new->red_file_name = NULL;
	new->previous = previous;
	if (previous != NULL)
		previous->next = new;
	p->list_token_size++;
	return (new);
}
