/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:41:24 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/21 14:34:36 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*

	Les fonction d'erreur qui affiche un certain message et renvoie -1.

	Ces fonctions seront surement à modifier.

*/

int ft_err_pars_bad_char(t_data_parsing *data_p, char c)
{
	ft_putstr_fd("Minishell: Unautorized character: ", 2);
	ft_putchar_fd(c, 2);
	ft_free_dp(data_p);
	return (-1);
}

int	ft_err_pars_message(t_data_parsing *data_p, char *message)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(message, 2);
	ft_free_dp(data_p);
	return (-1);
}

int	ft_err_pars(t_data_parsing *data_p)
{
	ft_putstr_fd("ERROR!\n", 2);
	perror("Minishell");
	ft_free_dp(data_p);
	return (-1);
}