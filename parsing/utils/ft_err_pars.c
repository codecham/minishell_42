/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:41:24 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/08 15:50:00 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	Les fonction d'erreur qui affiche un certain message et renvoie 
	une valeur négative.

*/

int	ft_err_pars_ambiguous(t_data_parsing *data_p, t_token *token, int err_code)
{
	ft_putstr_fd("Minshell: ", 2);
	ft_putstr_fd(token->value, 2);
	ft_putstr_fd(": ambigous redirect", 2);
	ft_free_dp(data_p);
	return (err_code);
}

int	ft_err_pars_near(t_data_parsing *data_p, char *str, int err_code)
{
	ft_putstr_fd("Minshell: parse error near `", 2);
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\'', 2);
	ft_free_dp(data_p);
	return (err_code);
}

int	ft_err_pars_bad_char(t_data_parsing *data_p, char c, int err_code)
{
	ft_putstr_fd("Minishell: Unautorized character: ", 2);
	ft_putchar_fd(c, 2);
	ft_free_dp(data_p);
	return (err_code);
}

int	ft_err_pars_message(t_data_parsing *data_p, char *message, int err_code)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(message, 2);
	ft_free_dp(data_p);
	return (err_code);
}

int	ft_err_pars_new_line(t_data_parsing *data_p, char *str, int err_code)
{
	if (str == NULL)
		ft_putstr_fd("Minishell: syntax error near unexpected token `newline\'",
			2);
	else
	{
		ft_putstr_fd("Minishell: syntax error near unexpected token `", 2);
		ft_putstr_fd(str, 2);
		ft_putchar_fd('\'', 2);
	}
	ft_free_dp(data_p);
	return (err_code);
}
