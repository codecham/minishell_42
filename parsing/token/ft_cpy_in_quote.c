/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_in_quote.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 04:03:16 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:07:57 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cpy_in_quote(t_token *token, char *input, int i)
{
	char	quote;

	quote = input[i];
	token->value = ft_realloc_add(token->value, input[i]);
	if (!token->value)
		return (-2);
	i++;
	while (input[i] && input[i] != quote)
	{
		token->value = ft_realloc_add(token->value, input[i]);
		if (!token->value)
			return (-2);
		i++;
	}
	if (input[i] == '\0')
		return (-1);
	token->value = ft_realloc_add(token->value, input[i]);
	if (!token->value)
		return (-2);
	return (i);
}
