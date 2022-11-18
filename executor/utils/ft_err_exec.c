/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:28:32 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 21:45:22 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_err_dup(void)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd("Duplicate fd error\n", 2);
	return (-1);
}

int	ft_err_fork(void)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd("Fork error\n", 2);
	return (-1);
}

int	ft_err_cmd_exist(t_node *node)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(node->command_name, 2);
	if (node->cmd_exist == -1)
		ft_putstr_fd(": command not found\n", 2);
	else if (node->cmd_exist == -2)
		ft_putstr_fd(": Is a directory\n", 2);
	else if (node->cmd_exist == -3)
		ft_putstr_fd(": Not a directory\n", 2);
	else if (node->cmd_exist == -4)
		ft_putstr_fd(": No such file or directory\n", 2);
	return (127);
}

void	ft_err_malloc_exec(void)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd("malloc error\n", 2);
}

int	ft_err_access(char *command_name)
{
	ft_putstr_fd("Minishell: permission denied: ", 2);
	ft_putstr_fd(command_name, 2);
	ft_putchar_fd('\n', 2);
	return (126);
}
