/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_redirection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 01:28:23 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:06:34 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_set_redirection(t_node *node, int redirect_type, int fd, char *f_name)
{
	t_redir_list	*new_element;
	t_redir_list	*tmp;

	tmp = node->redirection;
	new_element = (t_redir_list *)malloc(sizeof(t_redir_list));
	if (!new_element)
		return (-1);
	new_element->fd = fd;
	new_element->type = redirect_type;
	new_element->file_name = ft_strdup(f_name);
	if (!new_element->file_name)
		return (-1);
	new_element->next = NULL;
	if (node->redirection == NULL)
		node->redirection = new_element;
	else
	{
		while (node->redirection->next != NULL)
			node->redirection = node->redirection->next;
		node->redirection->next = new_element;
		node->redirection = tmp;
	}
	return (0);
}
