/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 18:31:19 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/07 03:16:57 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*


	Mais ou sinon le but de ces fonctions est de supprimer les possible elements vides de la liste. 
	Comme par exemple un token avec juste une variable d'environement qui n'existe pas.

*/

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
