/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/19 15:00:15 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Get the pathname that is the current working directory */
int	ft_builtin_pwd(int fd_out)
{
	char	*buf;

	buf = malloc(MAX_PATH_LEN * sizeof(char));
	if (!buf)
	{
		ft_putstr_fd("Minishell: cd: malloc error\n", 2);
		return (1);
	}
	getcwd(buf, MAX_PATH_LEN);
	if (!buf)
	{
		ft_putstr_fd("Minishell: cd: malloc error\n", 2);
		return (1);
	}
	ft_putendl_fd(buf, fd_out);
	free(buf);
	return (0);
}
