/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_here_doc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 22:45:32 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/18 03:11:43 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_line_is_empty(char *line)
{
	if (line[0] == '\0')
		return (1);
	return (0);
}

int	ft_err_code_hd(int tmp)
{
	if (g_exit_status == 130)
		return (-2);
	g_exit_status = tmp;
	return (-2);
}

int	ft_err_hd(void)
{
	ft_putstr_fd("Minishell: fork error\n", 2);
	return (-1);
}

int	ft_get_input_hd(t_data_parsing *p, t_token *t)
{
	char	*line;
	char	*line_w_env;

	while (1)
	{
		line = readline("> ");
		if (line == NULL)
			exit(131);
		if (ft_line_is_empty(line) == 0)
		{
			if (ft_strncmp(line, t->next->value,
					(ft_strlen(t->next->value + 1))) == 0)
				break ;
			line_w_env = ft_replace_env_hd(p, line);
			if (line_w_env == NULL)
				return (-1);
			ft_putstr_fd(line_w_env, t->fd);
			ft_putstr_fd("\n", t->fd);
			if (line_w_env)
				free(line_w_env);
		}
		if (line)
			free(line);
	}
	return (0);
}

int	ft_loop_here_doc(t_data_parsing *p, t_token *token)
{
	int	pid;
	int	exit_code;
	int	tmp;

	pid = fork();
	exit_code = 0;
	tmp = g_exit_status;
	if (pid < 0)
		return (ft_err_hd());
	else if (pid == 0)
	{
		ft_signal_heredoc();
		exit_code = ft_get_input_hd(p, token);
		if (exit_code == -1)
			ft_putstr_fd("Minishell: malloc error\n", 2);
		exit(1);
	}
	g_exit_status = 0;
	ft_signal_empty();
	ft_wait_children();
	if (g_exit_status >= 130)
		return (ft_err_code_hd(tmp));
	close(token->fd);
	return (exit_code);
}
