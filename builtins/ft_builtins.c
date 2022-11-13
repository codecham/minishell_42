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

#include "builtins.h"

int	ft_call_builtin(t_node *node, t_env *env)
{
	int	command;

	command = node->is_built_in;
	if (command == ECHO)
		ft_builtin_echo(node->arg, node->fd_out);
	else if (command == CD)
		ft_builtin_cd(node->arg[0]);
	else if (command == PWD)
		ft_builtin_pwd(node->fd_out);
	else if (command == EXPORT)
	{
		printf("command is export\n");
		ft_builtin_export(node->arg, env);
	}
	else if (command == UNSET)
	{
		printf("command is unset\n");
		//ft_builtin_unset(node->arg, node->fd_out, env);
	}
	else if (command == ENV)
	{
		printf("command is env\n");
		ft_builtin_env(node->fd_out, env);
	}
	else if (command == EXIT)
	{
		printf("command is exit\n");
		ft_builtin_exit(node->arg);
	}
	return (0);
}
