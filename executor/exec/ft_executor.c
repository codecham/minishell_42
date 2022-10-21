/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:11:00 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/06 13:06:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

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
		ft_exec_regular_cmd(data, data->first_node);
	}
	else if (data->first_node->redirection != NULL && data->first_node->next == NULL)
	{
		ft_set_redirection_fd(data->first_node);
		ft_exec_redirection(data, data->first_node);
	}
	else
	{
		ft_exec_pipe(data);
	}
}