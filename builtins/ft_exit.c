/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/19 15:47:50 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exit_print_error(char *str)
{
	ft_putstr_fd("Minishell: exit: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
}

int	ft_arg_is_num(char *arg)
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
		ft_putstr_fd("Minishel: exit: too many arguments\n", 2);
		return (1);
	}
	return (0);
}

/*
exit [n]
Exit the shell with a status of N.
*/
int	ft_builtin_exit(char **args, t_data *data)
{
	ft_putendl_fd("exit", 2);
	if (ft_too_many_args(args))
		return (EXIT_FAILURE);
	else
	{
		if (args[1] == NULL)
		{
			ft_free_data_exit(data);
			exit(EXIT_SUCCESS);
		}
		else
		{
			if (ft_arg_is_num(args[1]))
				g_exit_status = ft_atoi(args[1]);
			else
			{
				ft_exit_print_error(args[1]);
				g_exit_status = 255;
			}
			ft_free_data_exit(data);
			exit(g_exit_status);
		}
	}
	return (EXIT_SUCCESS);
}
