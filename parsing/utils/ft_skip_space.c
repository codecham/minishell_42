/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 07:38:11 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:09:54 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_skip_space(char *str, int i)
{
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		else
			return (i);
	}
	return (i);
}
