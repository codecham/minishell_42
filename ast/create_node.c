/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:10:31 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/10 03:05:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	init_node(t_node *node)
{
	node->type = -1;
	node->data = NULL;
	node->first_child = NULL;
	node->parent = NULL;
	node->previous = NULL;
	node->next = NULL;
	node->redirection = NULL;
}

t_node	*create_node(void)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	init_node(node);
	return (node);
}
