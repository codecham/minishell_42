/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_command_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 20:16:23 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/15 16:27:14 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

int		ft_add_command_name(t_node *node, char *command)
{
	node->command_name = ft_strdup(command);
	if (!node->command_name)
		return (-1);
	ft_add_arg_node(node, command);
	return (0);
}