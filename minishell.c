/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:52:04 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/07 05:31:02 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"
#include "parsing/parsing.h"
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

void	routine(t_data *data)
{
	char *line;

	while (1)
	{
		line = readline("Minishell> ");
		if (ft_only_space(line) == 0)
			ft_parsing(line, data->envp);
		add_history(line);
		if (line)
			free(line);
		printf("\n");
	}
}

int main(int argc, char **argv, char **envp)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->envp = envp;
	routine(data);
}