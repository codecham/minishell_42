/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 22:25:48 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/17 00:56:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	Cette fonction va simplement supprimer les quotes contenue 
	dans les tokens

	PARAMETRE D'ENTREE:
		- La structure t_data_parsing qui contient le pointeur 
		du premier element token
	
	VALEUR DE RETOUR:
		- Renvoie 0 si tout se passe bien.
		- Renvoie -1 en cas d'erreur de malloc

*/

int ft_contain_quotes(char *str)
{
	int i;

	i = 0;
	// printf("0.6");
	while (str[i])
	{
		// printf("0.7");
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_cpy_in_quotes(char *str, char *new, int *i, char quote)
{
	*i = *i + 1;
	while (str[*i] && str[*i] != quote)
	{
		new = ft_realloc_add(new, str[*i]);
		if (!new)
			return (NULL);
		*i = *i + 1;
	}
	return (new);
}

char	*ft_replace_quotes(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char));
	if (!new)
		return(NULL);
	new[0] = '\0';
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			new = ft_cpy_in_quotes(str, new, &i, str[i]);
			if (!new)
				return (NULL);
		}
		i++;
	}
	if (str)
		free(str);
	return (new);
}

int ft_delete_quotes(t_data_parsing *p)
{
	t_token *token;

	token = p->first_token;
	while (1)
	{
		if (token->type == WORDS && ft_contain_quotes(token->value) == 1)
		{
			token->value = ft_replace_quotes(token->value);
			if (!token->value)
				return (-1);
		}
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}