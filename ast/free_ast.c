/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:06:40 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/10 03:10:22 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

void	free_node(t_node *node)
{
	if (!node)
		return ;
	if (node->data)
		free(node->data);
	free(node);
}

void	free_childs(t_node *first_child)
{
	t_node	*last_child;

	if (!first_child)
		return ;
	last_child = get_last_node(first_child);
	while (last_child != NULL)
	{
		free_node(last_child);
		last_child = get_first_child(first_child);
	}
	free_node(first_child);
}

void	free_ast(t_node *node)
{
	t_node	*tmp;

	tmp = node->next;
	free_childs(node->first_child);
	free_redirection(node->redirection);
	free_node(node);
	if (tmp != NULL)
		free_ast(tmp);
}
