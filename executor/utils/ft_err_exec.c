/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:28:32 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/09 21:31:40 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_err_dup(void)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd("Duplicate fd error", 2);
	return (-1);
}
