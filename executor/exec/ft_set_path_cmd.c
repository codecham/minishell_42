/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_path_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:09:51 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:01:03 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_relative_path(char *command)
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

int	ft_set_relative_path(t_node *node)
{
	node->path_cmd = ft_strdup(node->command_name);
	if (!node->path_cmd)
		return (-1);
	if (access(node->command_name, F_OK) != 0)
		node->cmd_exist = -1;
	return (0);
}

int	ft_set_path_cmd(t_data *data)
{
	t_node	*node;

	node = data->first_node;
	while (1)
	{
		if (node->is_built_in == 0)
		{
			if (ft_is_relative_path(node->command_name) == 0)
			{
				if (ft_find_path_cmd(node, data->path_env) == -1)
					node->cmd_exist = -1;
			}
			else
			{
				if (ft_set_relative_path(node) == -1)
					return (-1);
			}
		}
		if (node->next == NULL)
			return (0);
		node = node->next;
	}
	return (0);
}
