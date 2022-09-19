/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:11:00 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/19 20:50:19 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

/*

	Fonction principale de l'execution.

	1) ft_get_path_env va copier les différents path dans la strcuture

	2) ft_is_builtin va checker si la commande est un builtin

	3) ft_set_path_cmd va set le path de l'executable

*/

void	ft_executor(t_data *data)
{
	data->path_env = ft_get_path_env(data->envp);
	if (!data->first_node || !data->path_env)
		return ;
	ft_is_builtin(data->first_node);
	if (ft_set_path_cmd(data) == -1)
		return ;
	if (data->first_node->redirection == NULL && data->first_node->next == NULL)
	{
		/*
			code pour commande sans pipe ni redirection
		*/
	}
	else if (data->first_node->redirection != NULL && data->first_node->next == NULL)
	{
		/*
			code pour commande sans pipe mais avec des redirections
		*/
	}
	else
	{
		/*
			code pour commande avec pipe
		*/
	}
}