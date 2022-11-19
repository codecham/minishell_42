/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:36:09 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 14:56:26 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_str_tolower(char *str)
{
	int		i;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	new = ft_strdup(str);
	if (!new)
		return (NULL);
	while (new[i])
	{
		new[i] = ft_tolower(new[i]);
		i++;
	}
	return (new);
}
