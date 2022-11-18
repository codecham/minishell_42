/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/18 04:22:09 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	cd_to_path(char *path, t_env *env)
{
	char	*oldpwd;

	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
		return (0);
	}
	oldpwd = malloc(MAX_PATH_LEN * sizeof(char));
	if (!oldpwd)
	{
		ft_putstr_fd("Minishell: cd: malloc error\n", 2);
		return (0);
	}
	getcwd(oldpwd, MAX_PATH_LEN);
	ft_update_env_var("OLDPWD", oldpwd, env);
	ft_update_env_var("PWD", ft_get_env_var("HOME", env), env);
	if (oldpwd)
		free(oldpwd);
	return (1);
}

int	cd_to_home(t_env *env)
{
	char	*home_dir;

	home_dir = getenv("HOME");
	if (!home_dir)
	{
		ft_putstr_fd("HOME is not set\n", 2);
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
