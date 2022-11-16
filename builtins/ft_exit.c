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

#include "../includes/minishell.h"

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

int	ft_count_args(char **args)
{
	int	counter;

	counter = 0;
	args++;
	while (*args != NULL)
	{
		counter++;
		args++;
	}
	return (counter);
}

int	ft_too_many_args(char **args)
{
	if (ft_count_args(args) > 1)
	{
		printf("minishel: exit: too many arguments\n");
		return (1);
	}
	return (0);
}

int	ft_builtin_exit(char **args)
{
	ft_putendl_fd("exit", 1);
	if (ft_too_many_args(args))
		return (EXIT_FAILURE);
	else
	{
		if (args[1] == NULL)
		{
			//free all malloc
			exit(EXIT_SUCCESS);
		}
		else
		{
			if (arg_is_num(args[1]))
				g_exit_status = ft_atoi(args[1]);
			else
			{
				printf("exit: %s: numeric argument required\n", args[1]);
				g_exit_status = 255;
			}
			//free all malloc
			exit(g_exit_status);
		}
	}
	return (EXIT_SUCCESS);
}
