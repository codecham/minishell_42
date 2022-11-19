/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 20:52:54 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 04:26:26 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_err_message_cd(char *str, int code)
{
	ft_putstr_fd("Minishell: cd: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (code);
}

int	ft_execute_cd_minus(t_env *env, char **arg, int fd_out)
{
	char	*oldpwd;
	int		exit_code;

	oldpwd = ft_get_env_var("OLDPWD", env);
	if (oldpwd == NULL)
	{
		ft_putstr_fd("Minishell: OLDPWD not set\n", 2);
		return (1);
	}
	else
	{
		if (arg[1])
			free(arg[1]);
		arg[1] = ft_strdup(oldpwd);
		if (!arg[1])
		{
			ft_putstr_fd("Minishell: cd: malloc error\n", 2);
			return (1);
		}
		exit_code = ft_builtin_cd(env, arg, fd_out);
		ft_builtin_pwd(fd_out);
	}
	return (exit_code);
}
