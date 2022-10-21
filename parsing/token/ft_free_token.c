/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:44:25 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/21 14:20:34 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*

	Cette fonction va simplement free la liste des token.

	PARAMETRE: Le premier element de la liste.

*/

void	ft_free_token(t_token *token)
{
	t_token *tmp;

	tmp = token->next;
	if (token)
	{
		if (token->value)
			free(token->value);
		free(token);
	}
	if (tmp != NULL)
		ft_free_token(tmp);
}