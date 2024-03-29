/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 22:52:04 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:27:55 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

t_data	*ft_initialize_data(t_data *data, char **envp)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->env_var_list = ft_get_env_var_list(envp);
	if (data->env_var_list == NULL)
	{
		free(data);
		return (NULL);
	}
	if (ft_update_shlv(data->env_var_list) == -1)
	{
		ft_free_env_var_list(data->env_var_list);
		free(data);
	}
	data->envp = ft_env_list_to_char(data->env_var_list);
	if (!data->envp)
	{
		ft_free_env_var_list(data->env_var_list);
		free(data);
	}
	data->first_node = NULL;
	data->path_env = NULL;
	return (data);
}

void	ft_quit_minishell(t_data *data)
{
	char		*up;
	char		*ri;

	ft_free_data(data);
	up = tgetstr("up", NULL);
	ri = tgetstr("RI", NULL);
	tputs(ri, 1, putchar);
	tputs(ri, 1, putchar);
	tputs(ri, 1, putchar);
	tputs(up, 1, putchar);
	ft_putstr_fd("exit\n", 2);
	exit(0);
}

void	routine(t_data *data)
{
	char	*line;

	while (1)
	{
		ft_signal_handler();
		line = readline("Minishell> ");
		if (line == NULL)
			ft_quit_minishell(data);
		if (ft_only_space(line) == 0)
		{
			add_history(line);
			ft_parsing(line, data);
		}
		else
		{
			g_exit_status = 0;
			if (line)
				free(line);
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*data;

	(void)argc;
	(void)argv;
	data = NULL;
	g_exit_status = 0;
	data = ft_initialize_data(data, envp);
	if (!data)
	{
		ft_putstr_fd("Minshell: malloc error\n", 2);
		return (1);
	}
	routine(data);
}
