/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/18 16:16:36 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cd_set_env_pwd(char *oldpwd, t_env *env)
{
	char	*pwd;

	pwd = malloc(MAX_PATH_LEN * sizeof(char));
	if (!pwd)
	{
		ft_putstr_fd("Minishell: cd: malloc error\n", 2);
		return (0);
	}
	getcwd(pwd, MAX_PATH_LEN);
	if (!pwd)
	{
		ft_putstr_fd("Minishell: cd: malloc error\n", 2);
		return (0);
	}
	ft_update_env_var("OLDPWD", oldpwd, env);
	ft_update_env_var("PWD", pwd, env);
	if (pwd)
		free(pwd);
	if (oldpwd)
		free(oldpwd);
	return (1);
}

int	cd_to_path(char *path, t_env *env)
{
	char	*oldpwd;

	oldpwd = malloc(MAX_PATH_LEN * sizeof(char));
	if (!oldpwd)
	{
		ft_putstr_fd("Minishell: cd: malloc error\n", 2);
		return (0);
	}
	getcwd(oldpwd, MAX_PATH_LEN);
	if (!oldpwd)
	{
		ft_putstr_fd("Minishell: cd: malloc error\n", 2);
		return (0);
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
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

	home_dir = getenv("HOME");
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
int	ft_builtin_cd(t_env *env, char *dir)
{
	if (dir == NULL)
	{
		if (!cd_to_home(env))
			return (1);
	}
	else
	{
		if (!cd_to_path(dir, env))
			return (1);
	}
	return (0);
}
