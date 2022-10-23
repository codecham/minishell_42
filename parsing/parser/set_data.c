/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:31:41 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/23 15:26:39 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*

	Cette fonction serivra à remplir les noeuds à partir de la liste des tokens.

	En travaux.
*/

int	ft_set_data(t_data_parsing *p)
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return(ft_err_pars_message(p, "malloc error\n", -1));
	return(0);
}