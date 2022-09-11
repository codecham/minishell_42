/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:06:40 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/11 18:07:15 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

/*
	La fonction ft_free_nodes va liberer tout l'espace memoire alloue dynamiquement de toute les nodes en les libereant dans l'ordre une par une.

	PARAMETRES:	- node: la premiere node de la liste.
*/

void	ft_free_matrice(char **matrice)
{
	int	i;

	i = 0;
	if (!matrice)
		return ;
	while (matrice[i])
	{
		if (matrice[i])
			free(matrice[i]);
		i++;
	}
	if (matrice)
		free(matrice);
}

void	ft_free_redirection(t_redir_list *element)
{
	t_redir_list	*tmp;

	if (element == NULL)
		return ;
	tmp = element->next;
	if (element)
		free(element);
	if (tmp != NULL)
		ft_free_redirection(tmp);
}

void	ft_free_one_node(t_node *node)
{
	if (!node)
		return ;
	if (node->command_name)
		free(node->command_name);
	if (node->arg)
		ft_free_matrice(node->arg);
	free(node);
}

void	ft_free_nodes(t_node *node)
{
	t_node	*tmp;

	tmp = node->next;
	ft_free_redirection(node->redirection);
	ft_free_one_node(node);
	if (tmp != NULL)
		ft_free_nodes(tmp);
}