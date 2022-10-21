/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:19:36 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/06 15:58:54 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

int	ft_run_pipe(t_data *data, t_node *node)
{
	if (node->redirection == NULL)
		return (ft_exec_simple_pipe(data, node));
	else
	{
		ft_close_bad_pipe(data->first_node, node);
		if (ft_set_fd_pipe(node) < 0)
			return (-1);
		return (ft_exec_pipe_red(data, node));
	}
	return(1);
}