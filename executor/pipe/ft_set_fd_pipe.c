/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fd_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 18:58:47 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:01:34 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_set_fd_pipe(t_node *node)
{
	if (node->pipe_in > 0)
	{
		if (dup2(node->pipe_in, 0) < 0)
			return (ft_err_dup());
	}
	if (node->pipe_out > 1 && node->next != NULL)
	{
		if (dup2(node->pipe_out, 1) < 0)
			return (ft_err_dup());
	}
	return (0);
}
