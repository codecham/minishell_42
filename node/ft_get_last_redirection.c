/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_last_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:50:24 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:06:08 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_redir_list	*ft_get_last_redirection(t_redir_list *li)
{
	t_redir_list	*tmp;

	tmp = li;
	if (li == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}
