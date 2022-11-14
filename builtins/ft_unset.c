/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/09 13:22:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "builtins.h"
#include "../includes/minishell.h"

/*
int	val_exist_in_envp(char *val, char **envp)
{

	return (0)
}
*/

int	ft_builtin_unset(char **args, int fd_out, char **envp)
{
	(void)fd_out;
	//(void)envp;
	(void)args;
	while (*envp != NULL)
	{
		//printf("%s\n", *args);
		printf("%s\n", *envp);
		/*
		if (val_exist_in_envp(*args, envp))
			printf("%s found in environment values\n");
		else
			printf("%s not found\n");
		*/
		envp++;
	}
	printf("%s\n", getenv("bububu"));
	//while arg is noy NULL
	// check if the variable exist,
	// exist: delete it
	// no exist pass to the next aegument
	return (0);
}
