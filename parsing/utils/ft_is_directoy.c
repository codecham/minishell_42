/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_directoy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:28:12 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/07 03:18:38 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int ft_is_directory(char *directory)
{
	DIR				*d;

	d = opendir(directory);
	if (!d)
		return (0);
	closedir(d);
	return (1);
}