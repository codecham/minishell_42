/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_word_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 03:54:57 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/21 14:28:14 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*

	La fonction ft_set_word_token copie tout le mot ou la string jusqu'à rencontrer un séparateur

	PARAMETRE: 
		- La structure t_data_parsing
		- Le token dans lequel ajouter le mot ou la string
		- L'input
		- L'indice ou se trouve le mot ou la string dans l'input

	VALEUR DE RETOUR:
		- Renvoie l'index de fin en cas de réussite.
		- Renvoie -1 si il y a une quote non fermée ou en cas d'erreur de malloc
*/

int ft_set_word_token(t_data_parsing *d, t_token *token, char *input, int i)
{
	while (input[i] && ft_is_separator(input[i]) == 0)
	{
		if (ft_autorized_char(input[i]) == -1)
			return (ft_err_pars_bad_char(d, input[i]));
		if (input[i] == '\"' || input[i] == '\'')
		{
			i = ft_cpy_in_quote(token, input, i);
			if (i == -1)
				return (ft_err_pars_message(d, "Unclosed Quote"));
			if (i == -2)
				return (ft_err_pars(d));
		}
		else
		{
			token->value = ft_realloc_add(token->value, input[i]);
			if (!token->value)
				return (ft_err_pars(d));
		}
		i++;
	}
	token->type = WORDS;
	return (i);
}