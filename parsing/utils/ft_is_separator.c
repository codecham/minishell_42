/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 07:01:23 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:09:35 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_is_separator(char c)
{
	if (c == ' ' || c == '\t' || c == '>' || c == '<' || c == '|')
		return (1);
	return (0);
}
