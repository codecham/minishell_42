/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_first_child.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:15:45 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/10 03:10:16 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ast.h"

t_node	*get_first_child(t_node *node)
{
	if (node == NULL || node->first_child == NULL)
		return (NULL);
	return (node->first_child);
}
