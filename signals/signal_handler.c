/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 19:41:08 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/08 19:46:44 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signal.h"

/* 

Ce fichier contient les différente fonctions à completer pour les différents signaux

*/

void	ft_signal_int(int sig) // fonction poour le signal ctrl+c
{

}

void	ft_signal_quit(int sig) // fonction pour le signal ctrl+\ //
{

}

void	ft_signal_handler(void)
{
	signal(SIGINT, ft_signal_int);
	signal(SIGQUIT, ft_signal_quit);
}
