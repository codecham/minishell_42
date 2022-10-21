/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:40:44 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/21 14:24:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"


/*

	La fonction ft_replace_env va chercher si il y a des variables d'environement
	à remplacer par leur valeur et l'envoie à ft_change_env_token.

	Ne le fait pas si la variable est entre simple quote (')

	PARAMETRES:
		- La structure t_data_parsing contenant le pointeur du premier element token.

	VALEUR DE RETOUR:
		- Renvoie 0 si tout se passe bien
		- Renvoie -1 si il y a une erreur de malloc.
*/

int	ft_search_env(t_token *token, char **envp)
{
	int	i;

	i = 0;
	while (token->value[i])
	{
		if (token->value[i] == '\'')
		{
			i++;
			while (token->value[i] != '\'')
				i++;
		}
		else
		{
			if (token->value[i] == '$')
			{
				if (ft_change_env_token(token, i, envp) == -1)
					return (-1);
			}
		}
		i++;
	}
	return(0);
}

int	ft_replace_env(t_data_parsing *p)
{
	t_token	*token;
	int		i;

	token = p->first_token;
	i = 0;
	while (1)
	{
		if (ft_search_env(token, p->envp) == -1)
			return (ft_err_pars(p));
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}