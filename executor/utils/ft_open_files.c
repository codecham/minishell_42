/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:13:14 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:02:41 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_err_files_message(char *name, char *message)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
	ft_putchar_fd('\n', 2);
	return (-1);
}

int	ft_check_access(t_redir_list *elem)
{
	if (access(elem->file_name, F_OK) == 0)
	{
		if (elem->type == OUTFILE || elem->type == OUTFILE_HAP)
		{
			if (access(elem->file_name, W_OK) != 0)
				return (-1);
		}
		else if (elem->type == INFILE)
		{
			if (access(elem->file_name, R_OK) != 0)
				return (-1);
		}
	}
	return (0);
}

int	ft_open_file_fd(t_redir_list *elem, char *file_name, int type)
{
	if (type == INFILE && (access(file_name, F_OK) == 0))
		elem->fd = open(file_name, O_RDONLY);
	else if (type == INFILE)
	{
		elem->fd = open(file_name, O_RDONLY | O_TRUNC, S_IRWXU);
		if (elem->fd == -1)
		{
			g_exit_status = 1;
			return (ft_err_files_message(elem->file_name,
					"No such file or directory"));
		}
	}
	else if (type == HEREDOC)
		elem->fd = open(file_name, O_RDONLY);
	else if (type == OUTFILE)
		elem->fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	else if (type == OUTFILE_HAP)
		elem->fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
	if (elem->fd == -1)
		return (ft_err_files_message(elem->file_name, "Can't open file"));
	return (0);
}

int	ft_open_files(t_node *node)
{
	t_redir_list	*elem;

	elem = node->redirection;
	while (1)
	{
		if (elem->type == OUTFILE || elem->type == OUTFILE_HAP)
		{
			if (ft_is_directory(elem->file_name) == 1)
				return (ft_err_files_message(elem->file_name,
						"Is a directory"));
		}
		if (ft_check_access(elem) == -1)
			return (ft_err_files_message(elem->file_name,
					"Permission denied"));
		if (ft_open_file_fd(elem, elem->file_name, elem->type) < 0)
			return (-1);
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
	return (0);
}
