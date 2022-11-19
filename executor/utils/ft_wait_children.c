/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_children.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:55:40 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:02:59 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_wait_children(void)
{
	int		status;
	int		signal;

	while (waitpid(-1, &status, 0) > 0)
	{
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
		{
			signal = WTERMSIG(status);
			g_exit_status = signal + 128;
		}		
	}
}
