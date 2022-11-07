/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 02:44:14 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/07 04:53:18 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_free_data(t_data *data)
{
	// if (data->first_token)
	// 	ft_free_token(data->first_token);
	if (data->first_node)
		ft_free_nodes(data->first_node);
	if (data)
		free(data);
	return (-1);	
}