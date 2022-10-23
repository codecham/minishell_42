/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_token_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:31:21 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/23 22:30:27 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

int	ft_create_token_list(t_data_parsing *data_p, char *input)
{
	int	exit_code;

	exit_code = ft_set_token_list(data_p, input);
	if (exit_code == -1)
		return (ft_err_pars_message(data_p, "malloc error\n", -1));
	else if (exit_code < 0)
		return (exit_code);
	if (ft_replace_env(data_p) == -1)
		return (ft_err_pars_message(data_p, "malloc error\n", -1));
	if (ft_delete_quotes(data_p) == -1)
		return (ft_err_pars_message(data_p, "malloc error\n", -1));
	ft_clear_token_list(data_p);
	return (0);
}
