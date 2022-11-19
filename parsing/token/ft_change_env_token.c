/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_change_env_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:50:04 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:07:34 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_change_env_ext(t_token *token, char *value, int saved_i, int i)
{
	int	value_size;

	value_size = 0;
	token->value = ft_swap_env_token(token, value, saved_i, i);
	if (value)
		value_size = ft_strlen(value);
	if (value)
		free (value);
	if (token->value == NULL)
		return (-1);
	return (value_size);
}

char	*ft_set_key(t_token *token, int *i)
{
	char	*key;

	key = NULL;
	if (token->value[*i] == '?')
	{
		key = ft_realloc_add(key, token->value[*i]);
		if (!key)
			return (NULL);
			*i = *i +1;
	}
	else
	{
		while (token->value[*i] && ft_good_c_for_env(token->value[*i]) == 1)
		{
			key = ft_realloc_add(key, token->value[*i]);
			if (key == NULL)
				return (NULL);
			*i = *i + 1;
			if (ft_isdigit(key[0]) == 1)
				break ;
		}
	}
	return (key);
}

int	ft_change_env_token(t_token *token, int i, char **envp)
{
	char	*key;
	char	*value;
	int		saved_i;

	saved_i = i;
	i++;
	if (token->value[i] == '\0')
		return (0);
	if (ft_good_c_for_env(token->value[i]) == -1 && token->value[i] != '?')
		return (0);
	key = ft_set_key(token, &i);
	if (key == NULL)
		return (-1);
	if (ft_get_env_value(key, &value, envp) == -1)
		return (-1);
	free(key);
	return (ft_change_env_ext(token, value, saved_i, i));
}
