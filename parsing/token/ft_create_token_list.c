/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_token_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:31:21 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/07 03:17:11 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_exit_code(t_data_parsing *p, int exit_code)
{
	if (exit_code == -1)
		return (ft_err_pars_message(p, "malloc error\n", -1));
	else
		return (exit_code);
}

int	ft_create_token_list(t_data_parsing *p, char *input)
{
	int	exit_code;

	exit_code = ft_set_token_list(p, input); 						// Creer la liste
	if (exit_code < 0)
		return (ft_exit_code(p, exit_code));
	if (ft_concat_redir(p) == -1)									// Concatene les redirection
		return (ft_err_pars_message(p, "malloc error\n", -1));
	exit_code = ft_check_syntax(p);								// Check la syntax
	if (exit_code < 0)
		return (ft_exit_code(p, exit_code));
	exit_code = ft_set_heredoc(p);									// Créer les heredoc
	if (exit_code < 0)
		return (ft_exit_code(p, exit_code));
	exit_code = ft_ambiguous_redirect(p);
	if (exit_code < 0)
		return (ft_exit_code(p, exit_code));
	if (ft_replace_env(p) == -1)
		return (ft_err_pars_message(p, "malloc error\n", -1));
	if (ft_delete_quotes(p) == -1)
		return (ft_err_pars_message(p, "malloc error\n", -1));
	exit_code = ft_set_red_file_name(p);
	if (exit_code < 0)
		return (ft_exit_code(p, exit_code));
	return (0);
}
