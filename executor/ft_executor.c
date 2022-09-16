/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:11:00 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/16 20:13:21 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

void	ft_executor(t_data *data)
{
	t_node *tmp;

	if (!data->first_node)
		return ;
	tmp = data->first_node;
	data->path_env = ft_get_path_env(data->envp);
	ft_is_builtin(data->first_node);
	ft_relative_path(data);
	while (1)
	{
		if (tmp->is_built_in == 0)
			printf("%s is not a built in\n", tmp->command_name);
		else
			printf("%s is a buitlins -> %d\n", tmp->command_name, tmp->is_built_in);
		printf("path_command = %s\n", tmp->path_cmd);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
}