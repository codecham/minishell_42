/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:33:08 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/18 02:57:31 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_create_heredoc(t_data_parsing *p, t_token *token)
{	
	token->red_file_name = ft_random_name();
	if (token->red_file_name == NULL)
		return (-1);
	token->fd = open(token->red_file_name, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (token->fd == -1)
		return (ft_err_pars_message(p, "Can't open file for heredoc", -2));
	return (0);
}

int	ft_set_heredoc(t_data_parsing *p)
{
	t_token	*token;
	int		exit_code;

	token = p->first_token;
	while (1)
	{
		if (token->type == HEREDOC)
		{
			exit_code = ft_create_heredoc(p, token);
			if (exit_code < 0)
				return (exit_code);
			exit_code = ft_loop_here_doc(p, token);
			if (exit_code < 0)
				return (exit_code);
		}
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}
