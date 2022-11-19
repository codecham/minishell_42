/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 20:11:26 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:06:28 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_node	*ft_new_node(t_node *previous_node)
{
	t_node	*new_node;

	new_node = ft_create_node();
	if (new_node == NULL)
		return (NULL);
	if (previous_node == NULL)
		return (new_node);
	while (previous_node->next != NULL)
		previous_node = previous_node->next;
	previous_node->next = new_node;
	new_node->previous = previous_node;
	return (new_node);
}
