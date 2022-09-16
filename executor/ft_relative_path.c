/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_relative_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:09:51 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/16 20:16:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int	ft_is_relative(char *command)
{
	int	i;

	i = 0;
	if (!command)
		return (0);
	while (command[i])
	{
		if (command[i] == '/')
			return (1);
		i++;
	}
	return (0);
}

int	ft_relative_path(t_data *data)
{
	t_node	*node;

	if (!data->first_node)
		return(-1);
	node = data->first_node;
	while (1)
	{
		if (ft_is_relative(node->command_name) == 0)
		{
			if (ft_find_path_cmd(node, data->path_env) == -1)
				return (-1);
		}
		else
		{
			node->path_cmd = ft_strdup(node->command_name);
			if (!node->path_cmd)
				return (-1);
		}
		if (node->next == NULL)
			return (0);
		node = node->next;
	}
	return (0);
}