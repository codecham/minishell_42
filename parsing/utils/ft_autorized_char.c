/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autorized_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:33:33 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/07 07:54:23 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	Cette fonction renvoie 0 si le c est un caractere autorisé et -1 si non.

*/

int ft_autorized_char(char c)
{
	char	unautorized_c[8] = "!#*&();`";
	int		i;

	i = 0;
	if (ft_isprint(c) == 0)
		return (-1);
	while (unautorized_c[i])
	{
		if (c == unautorized_c[i])
			return (-1);
		i++;
	}
	return (0);
}