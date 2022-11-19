/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/19 04:00:57 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cd_set_env_pwd(char *oldpwd, t_env *env)
{
	char	*pwd;

	pwd = malloc(MAX_PATH_LEN * sizeof(char));
	if (!pwd)
		return (ft_err_message_cd("malloc error", 0));
	getcwd(pwd, MAX_PATH_LEN);
	if (!pwd)
		return (ft_err_message_cd("malloc error", 0));
	if (!ft_update_env_var("OLDPWD", oldpwd, env))
	{
		if (oldpwd)
			free(oldpwd);
	}
	if (!ft_update_env_var("PWD", pwd, env))
	{
		if (pwd)
			free(pwd);
	}
	return (1);
}

int	cd_to_path(char *path, t_env *env)
{
	char	*oldpwd;

	oldpwd = malloc(MAX_PATH_LEN * sizeof(char));
	if (!oldpwd)
		return (ft_err_message_cd("malloc error", 1));
	getcwd(oldpwd, MAX_PATH_LEN);
	if (!oldpwd)
		return (ft_err_message_cd("malloc error", 1));
	if (chdir(path))
	{
		ft_putstr_fd("Minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		if (oldpwd)
			free(oldpwd);
		return (0);
	}
	return (cd_set_env_pwd(oldpwd, env));
}

int	cd_to_home(t_env *env)
{
	char	*home_dir;

	home_dir = ft_get_env_var("HOME", env);
	if (!home_dir)
	{
		ft_putstr_fd("HOME not set\n", 2);
		return (0);
	}
	return (cd_to_path(home_dir, env));
}

/*
Change the current directory to dir.
If the param dir is NULL, change the current directory to $HOME.
 */
int	ft_builtin_cd(t_env *env, char **arg, int fd_out)
{
	if (arg[1] == NULL)
	{
		if (!cd_to_home(env))
			return (1);
	}
	else if (arg[2] != NULL)
	{
		ft_putstr_fd("Minishell: cd: too few arguments\n", 2);
		return (1);
	}
	else if (arg[1][0] == '-')
		return (ft_execute_cd_minus(env, arg, fd_out));
	else
	{
		if (!cd_to_path(arg[1], env))
			return (1);
	}
	return (0);
}
