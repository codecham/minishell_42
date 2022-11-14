/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../includes/minishell.h"

/* check if -n is specified */
int	arg_is_option_n(char *arg)
{
	if (ft_strncmp(arg, "-n", ft_strlen(arg) + 1) == 0)
		return (1);
	return (0);
}

/*
Output the arguments.
If -n is specified, the trailing new line is suppressed.
*/
int	ft_builtin_echo(char **args, int fd_out)
{
	int	option_n;
	int	i;

	option_n = 0;
	i = 1;
	if (!args[i])
		ft_putstr_fd("\n", fd_out);
	else
	{
		if (arg_is_option_n(args[i]))
		{
			option_n = 1;
			i++;
		}
		while (args[i])
		{
			ft_putstr_fd(args[i], fd_out);
			if (args[i + 1])
				ft_putstr_fd(" ", fd_out);
			else if (!option_n)
				ft_putstr_fd("\n", fd_out);
			i++;
		}
	}
	return (0);
}
