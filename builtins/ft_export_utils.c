/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../includes/minishell.h"

int	ft_is_valid_first_char(char c)
{
	if (!ft_isalpha(c) && c != '_')
		return (0);
	return (1);
}

int	ft_is_valid_char(char c)
{
	if (ft_isalnum(c))
		return (1);
	if (c == '_')
		return (1);
	return (0);
}

int	ft_is_valid_syntax(char *arg, int *add_flag, int *equal_flag)
{
	int	i;

	i = 0;
	if (!ft_is_valid_first_char(arg[i]))
		return (0);
	while (arg[i] != '\0' && arg[i] != '=')
	{
		if (arg[i] == '+')
		{
			if (arg[i + 1] == '\0' || arg[i + 1] != '=')
				return (0);
			else
				*add_flag = 1;
		}
		else
		{
			if (!ft_is_valid_char(arg[i]))
				return (0);
		}
		i++;
	}
	if (arg[i] == '=')
		*equal_flag = 1;
	return (1);
}
