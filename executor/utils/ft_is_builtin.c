/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:14:44 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/18 18:04:10 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	La fonction ft_is_builtin regarde si la commande envoyé est un builtin ou pas
	et modifie la valeur dans la node en fonction des macro

	PARAMETRE : La premiere node.

*/

int	ft_err_malloc_exec_int(void)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd("malloc error\n", 2);
	return (-1);
}

void	ft_set_builtin(t_node *node, char *lower_cmd)
{
	if (ft_strncmp(lower_cmd, "echo",
			(ft_strlen(lower_cmd) + 1)) == 0)
		node->is_built_in = ECHO;
	else if (ft_strncmp(lower_cmd, "cd",
			(ft_strlen(lower_cmd) + 1)) == 0)
		node->is_built_in = CD;
	else if (ft_strncmp(lower_cmd, "pwd",
			(ft_strlen(lower_cmd) + 1)) == 0)
		node->is_built_in = PWD;
	else if (ft_strncmp(lower_cmd, "export",
			(ft_strlen(lower_cmd) + 1)) == 0)
		node->is_built_in = EXPORT;
	else if (ft_strncmp(lower_cmd, "unset",
			(ft_strlen(lower_cmd) + 1)) == 0)
		node->is_built_in = UNSET;
	else if (ft_strncmp(lower_cmd, "env",
			(ft_strlen(lower_cmd) + 1)) == 0)
		node->is_built_in = ENV;
	else if (ft_strncmp(lower_cmd, "exit",
			(ft_strlen(lower_cmd) + 1)) == 0)
		node->is_built_in = EXIT;
}

int	ft_is_builtin(t_node *node)
{
	t_node	*tmp;
	char	*lower_cmd;

	if (!node)
		return (0);
	tmp = node;
	while (1)
	{
		if (tmp->command_name != NULL)
		{
			lower_cmd = ft_str_tolower(tmp->command_name);
			if (!lower_cmd)
				return (ft_err_malloc_exec_int());
			ft_set_builtin(tmp, lower_cmd);
			free (lower_cmd);
		}
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	return (0);
}
