/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd_is_directory.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 21:28:32 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/15 21:45:22 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_get_len_before_slash(char *command)
{
	int	len;

	len = 0;
	while (*command != '\0' && *command != '/')
	{
		len++;
		command++;
	}
	if (*command == '\0')
		return (0);
	return (len);
}

int	ft_check_directory(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) < 0)
		return (0);
	return (S_ISDIR(buf.st_mode));
}

int	ft_check_file(char *path)
{
	struct stat	buf;

	if (stat(path, &buf) < 0)
		return (0);
	return (S_ISREG(buf.st_mode));
}

int	ft_command_is_dir(char *command, int *dir_found, int *file_found)
{
	int		path_len;
	char	*path;

	path_len = ft_get_len_before_slash(command);
	if (path_len == 0)
		return (0);
	path = (char *)malloc((path_len + 1) * sizeof(char));
	if (!path)
	{
		ft_err_malloc_exec();
		return (-1);
	}
	ft_strlcpy(path, command, path_len + 1);
	*dir_found = ft_check_directory(path);
	*file_found = ft_check_file(path);
	free(path);
	path = NULL;
	return (1);
}

/* return 0 if malloc error occured */
int	ft_check_cmd_syntax(t_node	*node)
{
	int		ret_val;
	int		d_found;
	int		f_found;

	while (node != NULL)
	{
		d_found = 0;
		f_found = 0;
		ret_val = ft_command_is_dir(node->command_name, &d_found, &f_found);
		if (ret_val == -1)
			return (0);
		if (ret_val == 1)
		{
			if (d_found == 1)
				node->cmd_exist = -2;
			else if (f_found == 1)
				node->cmd_exist = -3;
			else if (d_found == 0 && f_found == 0)
				node->cmd_exist = -4;
		}
		node = node->next;
	}
	return (1);
}
