/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_last_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:02:43 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/10 03:10:02 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_node	*get_last_node(t_node *node)
{
	t_node	*tmp;

	tmp = get_next_node(node);
	if (tmp == NULL || node == NULL)
		return (NULL);
	while (tmp->next != NULL)
		tmp = get_next_node(node);
	return (tmp);
}
