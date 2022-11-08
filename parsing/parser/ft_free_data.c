/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 02:44:14 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/07 18:52:54 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_free_data(t_data *data)
{
	if (data->first_node)
		ft_free_nodes(data->first_node);
	if (data)
		free(data);
	return (-1);
}
