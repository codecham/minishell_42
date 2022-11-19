/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_shlvl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 21:37:59 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/18 21:38:40 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*
Update (increment) the environment variable SHLVL.
Return: -1 if an error occured
*/
int	ft_update_shlv(t_env *env)
{
	char	*shlvl_str;
	int		shlvl_int;

	if (!env)
		return (0);
	shlvl_str = ft_get_env_var("SHLVL", env);
	if (!shlvl_str)
		return (0);
	shlvl_int = ft_atoi(shlvl_str);
	shlvl_int++;
	shlvl_str = ft_itoa(shlvl_int);
	if (!shlvl_str)
	{
		ft_putstr_fd("Minshell: malloc error\n", 2);
		return (-1);
	}
	if (!ft_update_env_var("SHLVL", shlvl_str, env))
	{
		free(shlvl_str);
		return (0);
	}
	return (1);
}
