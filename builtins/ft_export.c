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

int	ft_puterror(char *arg, char *str)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd("export", 2);
	ft_putstr_fd(": `", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd("': ", 2);
	ft_putendl_fd(str, 2);
	return (0);
}

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
		return (1);
	}
	while (*args != NULL)
	{
		if (!ft_is_valid_syntax(*args, &add_flag, &equal_flag))
			return (ft_puterror(*args, "not a valid identifier"));
		if (!equal_flag)
			return (1);
		key = ft_cpy_env_key(*args, add_flag);
		if (!key)
			return (0);
		if (ft_env_var_exist(key, env))
		{
			printf("EXIST\n");
			value = ft_getenv(key, env);
			printf("%s\n", value);
			// if addition mark is in str
			// 		join 2 string
			// else
			// 		assign new value
		}
		else
		{
			printf("NOT EXIST\n");
			// create new env_var
		}
			//{
			//	new_env_var = ft_new_env_var(*args);
			//	if (!new_env_var)
			//		return (0);
			//	env = ft_add_env_var(env, new_env_var);
			//}
		free(key);
		args++;
	}
	return (1);
}
