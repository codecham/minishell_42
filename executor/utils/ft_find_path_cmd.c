/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:16:12 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:02:08 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strncat_path(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	new = (char *)malloc(sizeof(char) * (i + j + 2));
	if (!new)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		new[i] = s1[i];
	new[i] = '/';
	i++;
	while (s2[++j])
		new[i + j] = s2[j];
	new[i + j] = '\0';
	return (new);
}

int	ft_check_in_path(char *command_name, char *directory)
{
	struct dirent	*dir;
	DIR				*d;

	d = opendir(directory);
	if (!d)
		return (-1);
	dir = readdir(d);
	while ((dir != NULL))
	{
		if (ft_strncmp(command_name, dir->d_name,
				ft_strlen(command_name) + 1) == 0)
		{
			closedir(d);
			return (0);
		}
		dir = readdir(d);
	}
	closedir(d);
	return (-1);
}

int	ft_find_path_cmd(t_node *node, char **path_env)
{
	int		i;
	char	*command_lower;

	i = 0;
	if (!node || !node->command_name || !path_env)
		return (-1);
	command_lower = ft_str_tolower(node->command_name);
	if (!command_lower)
		return (ft_err_malloc_exec_int());
	while (path_env[i])
	{
		if (ft_check_in_path(command_lower, path_env[i]) == 0)
		{
			node->path_cmd = ft_strncat_path(path_env[i], command_lower);
			free (command_lower);
			if (!node->path_cmd)
				return (-1);
			return (0);
		}
		i++;
	}
	free (command_lower);
	return (-1);
}
