/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:42:28 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/16 18:28:14 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
	Cette fonction va simplement envoyer le premier element pour free la 
	liste des token

	PARAMETRES: La structure t_data_parsing contenant le poiteur du premier 
	element
*/

void	ft_free_dp_error(t_data_parsing *data_p)
{
	if (data_p)
	{
		if (data_p->first_token)
			ft_free_token(data_p->first_token, 1);
		free(data_p);
	}
}

void	ft_free_dp(t_data_parsing *data_p)
{
	if (data_p)
	{
		if (data_p->first_token)
			ft_free_token(data_p->first_token, 0);
		free(data_p);
	}
}
