/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../includes/minishell.h"

/* Check if the argument is a number */
int	arg_is_num(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i] != '\0' && ft_isdigit(arg[i]))
		i++;
	if (arg[i] == '\0')
		return (1);
	return (0);
}

void	ft_builtin_exit(char **args)
{
	if (!arg_is_num(*args))
	{
		ft_putendl_fd("exit", 1);
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(*args, 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit (255);
	}
	else
		printf("ARG IS NUM\n");
}


/*
exit ++++1 -> numeric argument required
exit y y   -> numeric argument required
exit +1    -> (terminated with exit code)
exit ++1   -> numeric argument required
exit +-1   -> numeric ...
exit --1   -> numeric ...
exit -1    -> (terminated with exit code 255)
*/
