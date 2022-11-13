/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_env_var_list.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/13 01:30:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../builtins.h"

/* Add an environment variable to the linked list */
t_env	*ft_add_env_var(t_env *first_env_var, t_env *env_var)
{
	t_env	*tmp;

	if (first_env_var == NULL)
		first_env_var = env_var;
	else
	{
		tmp = first_env_var;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = env_var;
	}
	return (first_env_var);
}

/*
Create a linked list, which will contain all environment variables.
*/
t_env	*ft_get_env_var_list(char **envp)
{
	t_env	*first_env_var;
	t_env	*new_env_var;

	if (!envp)
		return (NULL);
	first_env_var = NULL;
	while (*envp)
	{
		new_env_var = ft_new_env_var(*envp);
		if (!new_env_var)
		{
			ft_free_env_var_list(first_env_var);
			return (NULL);
		}
		first_env_var = ft_add_env_var(first_env_var, new_env_var);
		envp++;
	}
	return (first_env_var);
}
