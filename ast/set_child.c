/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_child.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:00:05 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/10 03:09:38 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	set_child(t_node *parent, char *data)
{
	t_node	*child;
	t_node	*tmp;

	if (parent == NULL)
		return (NULL);
	child = create_node();
	if (child == NULL)
		return (NULL);
	if (parent->first_child == NULL)
	{
		parent->first_child = child;
		child->previous = NULL;
	}
	else
	{
		tmp = get_last_node(parent->first_child);
		child->previous = tmp;
	}
	child->next = NULL;
	child->parent = parent;
	child->type = ARG;
	child->data = ft_strdup(data);
}
