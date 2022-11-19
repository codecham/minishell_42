/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:05:18 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:08:32 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_set_separator(t_token *token, char sep)
{
	token->value = ft_realloc_add(token->value, sep);
	if (token->value == NULL)
		return (-1);
	if (sep == '>' || sep == '<')
		token->type = REDIRECTION;
	if (sep == '|')
		token->type = PIPE;
	return (0);
}

int	ft_loop_str_token(t_data_parsing *p, t_token *new, char *input, int i)
{
	while (input[i])
	{
		if (input[i] == ' ' | input[i] == '\t')
			i++;
		else
		{
			if (input[i] == '<' || input[i] == '>' || input[i] == '|')
			{
				if (ft_set_separator(new, input[i]) == -1)
					return (-1);
				i++;
			}
			else
				i = ft_set_word_token(p, new, input, i);
			if (i < 0)
				return (i);
		}
		if (input[i] && input[i] != ' ' && input[i] != '\t')
		{
			new = ft_create_token(new, p);
			if (!new)
				return (-1);
		}
	}
	return (0);
}

int	ft_set_token_list(t_data_parsing *p, char *input)
{
	t_token	*new;

	new = ft_create_token(NULL, p);
	if (!new)
		return (-1);
	p->first_token = new;
	return (ft_loop_str_token(p, new, input, ft_skip_space(input, 0)));
}
