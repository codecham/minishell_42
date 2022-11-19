/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:26:45 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 04:14:18 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	La fonction ft_get_env_value va rechercher la valeur associer à la variable 
	*key dans **envp et la stocke dans **value.

	Renvoie 1 si réussis

	Renvoie 0 si la variable n'existe pas

	Renvoie -1 en cas d'échec de malloc.
	
	ATTENTION A NE PAS OUBLIER DE FREE LA NOUVELLE STRING
*/

int	ft_set_exit_value(char **value)
{
	char	*tmp;

	tmp = ft_itoa(g_exit_status);
	if (!tmp)
		return (-1);
	*value = ft_strdup(tmp);
	if (tmp)
		free(tmp);
	if (!value)
		return (-1);
	return (1);
}

char	*ft_add_equal(char *key)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(key) + 2));
	if (!new)
		return (NULL);
	while (key[i])
	{
		new[i] = key[i];
		i++;
	}
	new[i] = '=';
	new[i + 1] = '\0';
	return (new);
}

int	ft_get_value(char *new, char *line, char **value)
{
	int	i;

	i = 0;
	while (new[i])
		i++;
	*value = ft_strdup(&line[i]);
	if (new)
		free (new);
	if (!value)
		return (-2);
	return (1);
}

int	ft_get_env_value(char *key, char **value, char **envp)
{
	int		i;
	char	*new;

	i = 0;
	if (!key || !envp)
		return (0);
	if (key[i] == '?')
	{
		return (ft_set_exit_value(value));
	}
	new = ft_add_equal(key);
	if (!new)
		return (-1);
	while (envp[i])
	{
		if (ft_strncmp(new, envp[i], ft_strlen(new)) == 0)
			return (ft_get_value(new, envp[i], value));
		i++;
	}
	free(new);
	*value = NULL;
	return (0);
}
