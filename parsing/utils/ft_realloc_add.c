/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 06:10:06 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:09:46 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_realloc_add(char *old, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (!old)
	{
		old = (char *)malloc(sizeof(char) * 2);
		old[0] = c;
		old[1] = '\0';
		return (old);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(old) + 2));
	if (!new)
		return (NULL);
	while (old[i])
	{
		new[i] = old[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	if (old)
		free(old);
	return (new);
}
