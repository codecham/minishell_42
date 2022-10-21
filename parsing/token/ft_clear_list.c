/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:31:19 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/21 13:17:56 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"


/*

	En travaux pour le moment.

	Mais ou sinon le but de ces fonctions est de supprimer les possible elements vides de la liste. 
	Comme par exemple un token avec juste une variable d'environement qui n'existe pas.

*/

void	ft_clear_one_token(t_token *token)
{
	if (token->value)
		free(token->value);
	if (token)
		free (token);
}

void	ft_delete_token_in_list(t_data_parsing *p, t_token *bad_token)
{
	t_token *token;

	token = p->first_token;
	while (1)
	{
		if (bad_token == token)
		{
			
		}
	}
}

int	ft_clear_empty_token(t_data_parsing *p)
{
	t_token	*token;

	token = p->first_token;
	while (1)
	{
		if (token->type == WORDS)
		{
			if (token->value && token->value[0] == '\0')
			{
				ft_delete_token_in_list(p, token);
				token = p->first_token;
				if (token == NULL)
					return (-1);
			}
		}
	}
}

int	ft_clear_token_list(t_data_parsing *p)
{
	t_token *token;
	t_token *pre_token;

	token = p->first_token;
	while (1)
	{
		if (token->type == WORDS)
		{
			if (ft_strlen(token->value) == 1 && token->value[0] == '\0')
			{

			}
		}
		
	}
	
}