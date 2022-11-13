/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/13 01:30:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

/* Init all str pointer to NULL */
void	ft_init_env_var(t_env *env_var)
{
	env_var->key = NULL;
	env_var->value = NULL;
	env_var->next = NULL;
}

/*
Create a new t_env structure, which will contain one environment variable.
The str parameter is the string from char **envp.
*/
t_env	*ft_new_env_var(char *str)
{
	t_env	*new_env_val;

	new_env_val = (t_env *)malloc(sizeof(t_env));
	if (!new_env_val)
		return (NULL);
	ft_init_env_var(new_env_val);
	new_env_val->key = ft_cpy_env_key(str);
	if (!new_env_val->key)
	{
		ft_free_env_var(new_env_val);
		return (NULL);
	}
	new_env_val->value = ft_cpy_env_val(str);
	if (!new_env_val->value)
	{
		ft_free_env_var(new_env_val);
		return (NULL);
	}
	return (new_env_val);
}
