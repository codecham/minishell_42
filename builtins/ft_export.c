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

#include "builtins.h"

//void	ft_export_error_msg()

int	ft_is_valid_syntax(char *str, int *addition_flag)
{

	printf("string to check : [%s]\n");
	if (!ft_isalpha(*str))
		return (0);
	// first char is not alphabet
	//		print error
	// there is a non-valid char
	//		print error
	// there is np equal char
	//		just dont create env_var (dont print error)

	// if there is + before =, add the char to the var(create this if is not exist)
	return (1);
}

int	ft_builtin_export(char **args, t_env *env)
{
	t_env	*new_env_var;
	int		addition_flag;

	addition_flag = 0;
	if (*args == NULL)
	{
		printf("need to print env variable in sort\n");
		return (1);
	}
	while (*args != NULL)
	{
		if (ft_is_valid_syntax(*args, &addition_flag))
		{
			if (ft_env_var_exist(env, *args) && addition_flag)
				// join the two string
			else if (ft_env_var_exist(env, *args) && !addition_flag)
				// modified the string
			else if (!ft_env_var_exist(env, *args))
			{
				new_env_var = ft_new_env_var(*args);
				if (!new_env_var)
					return (0);
				env = ft_add_env_var(env, new_env_var);
			}
		}
		else
		{
			printf("not a valid identifier\n");
		}
		args++;
	}
	return (1);
}
