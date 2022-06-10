/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_redirection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:01:03 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/10 03:04:20 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_redir_list	*get_next_redirection(t_redir_list *li)
{
	if (li == NULL)
		return (NULL);
	else
		return (li->next);
}
