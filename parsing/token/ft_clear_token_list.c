/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:31:19 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/24 01:03:13 by dcorenti         ###   ########.fr       */
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
	if (p->list_token_size == 1)
	{
		ft_clear_one_token(token);
		p->first_token = NULL;
		p->list_token_size--;
		return ;
	}
	while (token != bad_token)
		token = token->next;
	if (token->previous == NULL)
	{
		p->first_token = token->next;
		token->next->previous = NULL;
	}
	else
	{
		token->previous->next = token->next;
		if (token->next != NULL)
			token->next->previous = NULL;
	}
	ft_clear_one_token(token);
	token = NULL;
	p->list_token_size--;
}

void	ft_clear_token_list(t_data_parsing *p)
{
	t_token *token;

	token = p->first_token;
	while (1)
	{
		if (token->type == WORDS)
		{
			if (ft_strlen(token->value) == 0)
			{
				ft_delete_token_in_list(p, token);
				if (p->list_token_size == 0)
					return ;
			}
		}
		if (token->next == NULL)
			break ;
		token = token->next;
	}
}
