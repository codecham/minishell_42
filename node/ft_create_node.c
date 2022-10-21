/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:55:43 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/06 12:32:06 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

/*
	Fonction créant un nouveau noeud et initialisant les données de ce dernier.

	VALEUR DE RETOUR: renvoie le nouveau noeud ou NULL si l'allocation échoue
*/

t_node	*ft_create_node(void)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->command_name = NULL;
	new_node->path_cmd = NULL;
	new_node->arg = NULL;
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->redirection = NULL;
	new_node->is_built_in = 0;
	new_node->fd_in = 0;
	new_node->fd_out = 1;
	new_node->pipe_in = 0;
	new_node->pipe_out = 0;
	new_node->pid = 0;
	new_node->saved_fd = malloc(sizeof(t_saved_fd));
	if (!new_node->saved_fd)
		return (NULL);
	return (new_node);
}