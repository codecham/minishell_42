/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_env_var.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/13 01:30:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* Free an environment variable */
void	ft_free_env_var(t_env *env_var)
{
	if (env_var->key != NULL)
	{
		free(env_var->key);
		env_var->key = NULL;
	}
	if (env_var->value != NULL)
	{
		free(env_var->value);
		env_var->value = NULL;
	}
	free(env_var);
	env_var = NULL;
}

/* Free each environment variables of the linked list */
void	ft_free_env_var_list(t_env *env_var)
{
	t_env	*env_var_next;

	if (env_var == NULL)
		return ;
	while (env_var != NULL)
	{
		env_var_next = env_var->next;
		ft_free_env_var(env_var);
		env_var = env_var_next;
	}
}
