/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:46:26 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/18 03:14:57 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	La fonction ft_replace_env va chercher si il y a des variables
	d'environement à remplacer par leur valeur et l'envoie à
	ft_change_env_token.

	Ne le fait pas si la variable est entre simple quote (')

	PARAMETRES:
		- La structure t_data_parsing contenant le pointeur du 
		premier element token.

	VALEUR DE RETOUR:
		- Renvoie 0 si tout se passe bien
		- Renvoie -1 si il y a une erreur de malloc.
*/

int	ft_env_in_double_quote(t_token *token, int i, char **envp)
{
	int	result;

	i++;
	while (token->value[i] && token->value[i] != '\"')
	{
		if (token->value[i] == '$')
		{
			result = ft_change_env_token(token, i, envp);
			if (result == -1)
				return (-1);
			i += result;
		}
		i++;
	}
	return (i + 1);
}

int	ft_env_in_quote(t_token *token, int i)
{
	i++;
	while (token->value[i] && token->value[i] != '\'')
		i++;
	return (i + 1);
}

int	ft_env_without_quote(t_token *token, int i, char **envp)
{
	int	result;

	while (token->value[i])
	{
		if (token->value[i] == '\"' && token->value[i] == '\'')
			break ;
		if (token->value[i] == '$')
		{
			result = ft_change_env_token(token, i, envp);
			if (result == -1)
				return (-1);
			i += result;
			return (i);
		}
		i++;
	}
	return (i);
}

int	ft_search_env(t_token *token, char **envp)
{
	int	i;

	i = 0;
	while (token->value[i])
	{
		if (token->value[i] == '\'')
			i = ft_env_in_quote(token, i);
		else if (token->value[i] == '\"')
			i = ft_env_in_double_quote(token, i, envp);
		else
			i = ft_env_without_quote(token, i, envp);
		if (i == -1)
			return (-1);
	}
	return (0);
}

int	ft_replace_env(t_data_parsing *p)
{
	t_token	*token;

	token = p->first_token;
	while (1)
	{
		if (token->type == WORDS)
		{
			if (ft_search_env(token, p->envp) == -1)
				return (-1);
		}
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}
