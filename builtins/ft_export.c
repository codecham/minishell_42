/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../includes/minishell.h"

int	ft_update_env_var_list(char *key, char *value, t_env *env)
{
	t_env	*new_env_var;

	if (ft_is_env_var_exist(key, env))
	{
		ft_update_env_var(key, value, env);
		free(key);
	}
	else
	{
		new_env_var = ft_new_env_var(key, value);
		if (!new_env_var)
		{
			free(key);
			free(value);
			return (0);
		}
		env = ft_add_env_var(env, new_env_var);
	}
	return (1);
}

int	ft_export_env_var(char *str, int add_flag, t_env *env)
{
	char	*key;
	char	*value;

	key = ft_cpy_env_key(str, add_flag);
	if (!key)
		return (0);
	value = ft_get_new_env_val(str, key, &add_flag, env);
	if (!value)
	{
		free(key);
		return (0);
	}
	if (!ft_update_env_var_list(key, value, env))
		return (0);
	return (1);
}

int	ft_builtin_export(char **args, t_env *env)
{
	int		add_flag;
	int		equal_flag;

	args++;
	if (*args == NULL)
	{
		//ft_put_env_var_sort_list(env); //wip
		return (0);
	}
	while (*args != NULL)
	{
		add_flag = 0;
		equal_flag = 0;
		if (ft_is_valid_export(*args, &add_flag, &equal_flag))
		{
			if (equal_flag)
			{
				if (!ft_export_env_var(*args, add_flag, env))
					return (1);
			}
		}
		else
			ft_puterror(*args, "not a valid identifier");
		args++;
	}
	ft_builtin_env(1, env);
	return (0);
}
