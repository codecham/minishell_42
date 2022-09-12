/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:55:43 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/12 20:20:23 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

/*
	Fonction créant un nouveau noeud et initialisant les données de ce dernier.

	VALEUR DE RETOUR: renvoie le nouveau noeud ou NULL si l'allocation échoue
*/

t_node	*ft_create_node(void)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->command_name = NULL;
	new_node->arg = NULL;
	new_node->next = NULL;
	new_node->previous = NULL;
	new_node->redirection = NULL;
	return (new_node);
}
