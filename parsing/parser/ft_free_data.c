/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 02:44:14 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/14 17:59:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	ft_free_env_var_list(t_env *elem)
// {
// 	t_env *next;

// 	if (elem == NULL)
// 		return ;
// 	next = elem->next;
// 	if (elem->value)
// 		free(elem->value);
// 	if (elem->key)
// 		free(elem->key);
// 	if (elem->next != NULL)
// 		ft_free_env_var_list(next);
// }

int	ft_free_data(t_data *data)
{
	if (data->first_node)
		ft_free_nodes(data->first_node);
	ft_free_matrice(data->path_env);
	ft_free_env_var_list(data->env_var_list);
	if (data)
		free(data);
	return (-1);
}
