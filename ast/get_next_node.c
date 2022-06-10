/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:44:15 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/10 03:09:42 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_node	*get_next_node(t_node *node)
{
	if (node == NULL || node->next == NULL)
		return (NULL);
	return (node->next);
}
