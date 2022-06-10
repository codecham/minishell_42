/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_previous_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 16:47:01 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/10 03:05:53 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_node	*get_previous_node(t_node *node)
{
	if (node == NULL || node->previous == NULL)
		return (NULL);
	return (node->previous);
}
