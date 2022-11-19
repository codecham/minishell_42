/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 02:06:40 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:06:01 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_free_matrice(char **matrice)
{
	int	i;

	i = 0;
	if (!matrice)
		return ;
	while (matrice[i])
	{
		if (matrice[i])
			free(matrice[i]);
		i++;
	}
	if (matrice)
		free(matrice);
}

void	ft_free_redirection(t_redir_list *element)
{
	t_redir_list	*tmp;

	if (element == NULL)
		return ;
	tmp = element->next;
	if (element->type == HEREDOC)
		unlink(element->file_name);
	if (element->fd > 0)
	{
		close(element->fd);
		element->fd = -1;
	}
	if (element->file_name)
		free(element->file_name);
	if (element)
		free(element);
	if (tmp != NULL)
		ft_free_redirection(tmp);
}

void	ft_free_one_node(t_node *node)
{
	if (!node)
		return ;
	if (node->command_name)
		free(node->command_name);
	if (node->path_cmd)
		free(node->path_cmd);
	if (node->arg)
		ft_free_matrice(node->arg);
	free(node);
}

void	ft_free_nodes(t_node *node)
{
	t_node	*tmp;

	tmp = node->next;
	ft_free_redirection(node->redirection);
	ft_free_one_node(node);
	if (tmp != NULL)
		ft_free_nodes(tmp);
}
