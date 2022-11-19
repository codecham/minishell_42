/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_redir_next.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:39:01 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:07:43 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_two_pipe(t_token *token)
{
	if (token->next->next != NULL && token->next->next->type == PIPE)
		return ("||");
	else
		return ("|");
}

int	ft_check_redir_next(t_data_parsing *p, t_token *token)
{
	if (token->type == INFILE || token->type == OUTFILE
		|| token->type == OUTFILE_HAP || token->type == HEREDOC)
	{
		if (token->next == NULL)
			return (ft_err_pars_new_line(p, NULL, ERROR));
		if (ft_is_redirection(token->next) == 1)
			return (ft_err_pars_new_line(p, token->next->value, ERROR));
		if (token->next->type == PIPE)
			return (ft_err_pars_new_line(p, ft_two_pipe(token), ERROR));
	}
	return (0);
}
