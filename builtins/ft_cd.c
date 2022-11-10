/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	cd_to_path(char *path, int fd_out)
{
	if (chdir(path) == -1)
	{
		ft_putstr_fd("minishell: cd: ", fd_out);
		ft_putstr_fd(path, fd_out);
		ft_putstr_fd(": ", fd_out);
		ft_putendl_fd(strerror(errno), fd_out);
		return (0);
	}
	return (1);
}

int	cd_to_home(int fd_out)
{
	char	*home_dir;

	home_dir = getenv("HOME");
	if (!home_dir)
		return (0);
	return (cd_to_path(home_dir, fd_out));
}

int	builtin_cd(char **args, int fd_out)
{
	(void)fd_out;
	if (!*args)
	{
		if (!cd_to_home(fd_out))
			return (-1);
	}
	else
	{
		if (!cd_to_path(*args, fd_out))
			return (-1);
	}
	return (0);
}
