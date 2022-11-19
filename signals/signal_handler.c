/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:41:08 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/18 22:07:08 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
Ce fichier contient les différente fonctions à completer pour les
différents signaux
*/

void	ft_signal_int_child(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', 2);
}

void	ft_signal_int(int sig)
{
	(void)sig;
	g_exit_status = 1;
	ft_putchar_fd('\n', 2);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_signal_handler(void)
{
	signal(SIGINT, ft_signal_int);
	signal(SIGQUIT, SIG_IGN);
}

void	ft_signal_handler_child(void)
{
	signal(SIGINT, ft_signal_int_child);
	signal(SIGQUIT, SIG_IGN);
}
