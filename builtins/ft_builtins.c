/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../includes/minishell.h"

int	ft_call_builtin(t_node *node, t_env *env)
{
	int	command;

	command = node->is_built_in;
	if (command == ECHO)
		ft_builtin_echo(node->arg, node->fd_out);
	else if (command == CD)
		ft_builtin_cd(node->arg[1]);
	else if (command == PWD)
		ft_builtin_pwd(node->fd_out);
	else if (command == EXPORT)
	{
		//ft_builtin_export(node->arg, env);
		printf("command is export...wip\n");
	}
	else if (command == UNSET)
	{
		//ft_builtin_unset(node->arg, node->fd_out, env);
		printf("command is unset...wip\n");
	}
	else if (command == ENV)
		ft_builtin_env(node->fd_out, env);
	else if (command == EXIT)
	{
		printf("command is exit...wip\n");
		//ft_builtin_exit(node->arg);
	}
	return (0);
}
