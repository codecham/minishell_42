/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 05:58:16 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/06 12:26:30 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

/*
	La fonction ft_exec_redirection va executer la commande après
	avoir modifier les fd de STDIN et/ou STDOUT.
	Ensuite la fonction s'occupe de fermer les autres fichiers possiblement encore ouvert.

	PARAMETRE: La structure data, la node contenant la commande à executer,
	la structure contenant la sauvegarde des fd mofifiés 

	VALEUR DE RETOUR: A MODIFIER!
*/

void	ft_close_fd(t_node *node, t_saved_fd *saved_fd)
{
	t_redir_list *elem;

	if (!node->redirection)
		return ;
	elem = node->redirection;
	while (1)
	{
		if (elem->fd != saved_fd->fd_infile && elem->fd != saved_fd->fd_outfile)
			close(elem->fd);
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
}

int	ft_exec_redirection(t_data *data, t_node *node)
{
	t_node *tmp;
	
	tmp = node;
	if (tmp->is_built_in != 0)
	{
		/*
			code pour builtins
		*/
		printf("%s is a builtin\n", tmp->command_name);
	}
	else
	{
		ft_exec_regular_cmd(data, tmp);
		ft_reset_saved_fd(node);
		ft_close_fd(tmp, tmp->saved_fd);
		if (tmp->saved_fd)
			free(tmp->saved_fd);
	}
	return (0);
}