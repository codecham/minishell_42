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

int	ft_builtin_export(char **args, t_env *env)
{
	//t_env	*new_env_var;
	int		add_flag;
	int		equal_flag;
	char	*key;
	char	*value;

	args++;
	add_flag = 0;
	equal_flag = 0;
	if (*args == NULL)
	{
		printf("need to print env variable in sort\n");
		return (0);
	}
	while (*args != NULL)
	{
		if (!ft_is_valid_export(*args, &add_flag, &equal_flag))
			return (ft_puterror(*args, "not a valid identifier"));
		if (!equal_flag)
			return (0);
		key = ft_cpy_env_key(*args, add_flag);
		if (!key)
			return (1);
		value = ft_get_new_env_val(*args, key, &add_flag, env);
		if (!value)
		{
			free(key);
			return (1);
		}
		if (ft_env_var_exist(key, env))
		{
			ft_update_env_value(key, value, env);
		}
		else
		{
			printf("NOT EXIST need to create one.\n");
		}
		free(key);
		args++;
	}
	return (0);
}
