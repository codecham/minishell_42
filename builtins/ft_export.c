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

/* Update the value of the environment variable found with key. */
int	ft_update_env_value(char *key, char *new_value, t_env *env)
{
	t_env	*env_var;

	env_var = env;
	while (env_var != NULL)
	{
		if (ft_strncmp(key, env_var->key, ft_strlen(key) + 1) == 0)
		{
			free(env_var->value);
			env_var->value = NULL;
			env_var->value = new_value;
			return (1);
		}
		env_var = env_var->next;
	}
	return (0);
}

char	*ft_get_new_env_val(char *str, char *key, int *add_flag, t_env *env)
{
	char	*value;
	char	*return_value;

	value = ft_cpy_env_val(str);
	if (!value)
		return (NULL);
	if (*add_flag)
	{
		return_value = ft_strjoin(value, ft_getenv(key, env));
		free(value);
		value = NULL;
	}
	else
		return_value = value;
	return (return_value);
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
		value = ft_get_new_env_val(*args, key, &add_flag, env);
		if (!value)
		{
			free(key);
			return (0);
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
	return (1);
}
