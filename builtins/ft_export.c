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

int	ft_is_invalid_char(char c)
{
	(void)c;
	// _ ok
	// + ok but only before =
	return (1);
}
/*
Invalid Syntax:
*/
int	ft_is_valid_syntax(char *str, int *addition_flag)
{
	int	equal_sign;
	int	i;

	i = 0;
	printf("string to check : [%s]\n", str);
	if (!ft_isalpha(str[0]) || str[0] != '_')
		return (ft_puterror(str, "not a valid identifier"));
	equal_sign = 0;
	while (str[i] != '\0')
	{
		if (ft_is_invalid_char(str[i]))
			return (ft_puterror(str, "not a valid identifier"));
		if (str[i] == '=')
			equal_sign++;
		if (str[i] == '+')
			*addition_flag = 1;
		i++;
	}
	// there is a non-valid char
	//		print error
	// there is np equal char
	//		just dont create env_var (dont print error)

	// if there is + before =, add the char to the var(create this if is not exist)
	return (1);
}

int	ft_builtin_export(char **args, t_env *env)
{
	//t_env	*new_env_var;
	int		addition_flag;
	int		i;
	char	*key;
	//char	*value;

	(void)env;
	i = 1;
	addition_flag = 0;
	if (args[i] == NULL)
	{
		printf("need to print env variable in sort\n");
		return (1);
	}
	while (args[i] != NULL)
	{

		if (ft_is_valid_syntax(args[i], &addition_flag))
		{
			key = ft_cpy_env_key(args[i]);
			if (!key)
				return (0);
			if (ft_env_var_exist(key, env))
			{
				if (addition_flag)
					printf("need to get value end join the str\n");
				else
					printf("need to assign new value\n");
			}
			else
				printf("need to create new env_var struct\n");
			//{
			//	new_env_var = ft_new_env_var(*args);
			//	if (!new_env_var)
			//		return (0);
			//	env = ft_add_env_var(env, new_env_var);
			//}
		}
		else
		{
			return (0);
		}
		i++;
	}
	return (1);
}
