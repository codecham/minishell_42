/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:44:25 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:08:19 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_free_token(t_token *token, int heredoc_unlink)
{
	t_token	*tmp;

	if (token == NULL)
		return ;
	tmp = token->next;
	if (token)
	{
		if (token->value)
			free(token->value);
		if (token->red_file_name)
		{
			if (token->type == HEREDOC && heredoc_unlink == 1)
				unlink(token->red_file_name);
			free(token->red_file_name);
		}
		free(token);
	}
	if (tmp != NULL)
		ft_free_token(tmp, heredoc_unlink);
}
