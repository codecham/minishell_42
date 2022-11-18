/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:48:06 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/18 03:12:15 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_signal_int_hd(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', 2);
	exit(0);
}

void	ft_signal_heredoc(void)
{
	signal(SIGINT, ft_signal_int_hd);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_signal_int_hd_empty(int sig)
{
	(void)sig;
	g_exit_status = 130;
}

void	ft_signal_empty(void)
{
	signal(SIGINT, ft_signal_int_hd_empty);
	signal(SIGQUIT, SIG_IGN);
}
