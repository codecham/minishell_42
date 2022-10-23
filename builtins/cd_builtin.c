/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:37:46 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/21 13:22:37 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

/*


	En travaux aussi.

*/

int		ft_exec_cd(char path, char **envp)
{
	if (!(access(path, F_OK)))
		ft_putstr_fd("cd: no such file or directory: %s\n", path);
	else if (!(access(path, W_OK)))
		ft_putstr_fd("cd: permission denied: %s\n", path);
	else
	{
		
	}
}

int		cd_builtin(char **argv, char **envp)
{
	char	*path;
	int		i;

	i = 0;
	g_exit_status = 0;
	if (!argv[1])
	{
		path = ft_get_env_by_key("HOME=", envp);
		if (path == NULL)
		{
			g_exit_status = 1;
			ft_putstr_fd("minishell: cd: HOME not set\n", 2);
			return(-1);
		}
	}
	else
		path = argv[1];
}