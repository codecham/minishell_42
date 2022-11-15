/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../includes/minishell.h"

/*
int	val_exist_in_envp(char *val, char **envp)
{

	return (0)
}
*/

int	ft_is_valid_unset(char *arg)
{
	int	i;

	i = 0;
	if (!ft_is_valid_first_char(arg[i]))
		return (0);
	while (arg[i] != '\0')
	{
		if (!ft_is_valid_char(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_builtin_unset(char **args, t_env *env)
{
	args++;
	while (*args != NULL)
	{
		printf("arg to check: %s\n", *args);
		if (!ft_is_valid_unset(*args))
			return (ft_puterror(*args, "not a valid identifier"));
		if (ft_env_var_exist(*args, env))
			printf("have to delete this env_var\n");
		/*
		if (val_exist_in_envp(*args, envp))
			printf("%s found in environment values\n");
		else
			printf("%s not found\n");
		*/
		args++;
	}
	//while arg is noy NULL
	// check if the variable exist,
	// exist: delete it
	// no exist pass to the next aegument
	return (0);
}
