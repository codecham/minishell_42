/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:00:14 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/22 18:45:15 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

int	ft_exec_pipe(t_data *data)
{
	t_node *node;

	node = data->first_node;
	ft_create_pipe(data);
	if (node->is_built_in != 0)
	{
		/*
			code pour builtin
		*/
	}
	else
	{
		while (1)
		{
			node->pid = fork();
			if (node->pid < 0)
			{
				/*
					code pour failed fork
				*/
				return (-1);
			}
			else if (node->pid == 0)
				ft_run_pipe(data, node);
			if (node->next == NULL)
				break;
			node = node->next;
		}
	}
	return(0);
}