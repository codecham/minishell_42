/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_env_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:15:56 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:08:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_cpy_empty_env(t_token *token, int begin, int end)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = malloc(sizeof(char) * ft_strlen(token->value) - (end - begin) + 1);
	if (!new)
		return (NULL);
	while (i < begin)
	{
		new[i] = token->value[i];
		i++;
	}
	j = i;
	while (i < end)
		i++;
	while (token->value[i])
	{
		new[j] = token->value[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_copy_string_env(t_token *token, char *value, int begin, int end)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	j = -1;
	new = (char *)malloc(sizeof(char) * (ft_strlen(value)
				+ ft_strlen(token->value) - (end - begin) + 2));
	if (!new)
		return (NULL);
	while (++i < begin)
		new[i] = token->value[i];
	while (value[++j])
		new[i + j] = value[j];
	j = i + j;
	i = end;
	while (token->value[i])
	{
		new[j] = token->value[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

char	*ft_swap_env_token(t_token *token, char *value, int begin, int end)
{
	char	*new;

	if (value == NULL)
		new = ft_cpy_empty_env(token, begin, end);
	else if (ft_strlen(token->value) - ((end - begin) - 1) < 1)
		new = ft_strdup(value);
	else
		new = ft_copy_string_env(token, value, begin, end);
	if (token->value)
		free(token->value);
	if (!new)
		return (NULL);
	token->value = new;
	return (token->value);
}
