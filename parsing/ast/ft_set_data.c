/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:31:41 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:06:49 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_loop_node_data(t_node *node, t_token *token)
{
	int	exit_code;

	while (1)
	{
		if (ft_is_redirection(token) == 1)
			exit_code = ft_fill_redirection(node, token);
		else if (token->type == WORDS && node->command_name == NULL
			&& ft_is_empty_token(token) == 0)
			exit_code = ft_add_command_name(node, token->value);
		else if (token->type == WORDS)
			exit_code = ft_add_arg_node(node, token->value);
		else if (token->type == PIPE)
			node = ft_new_node(node);
		if (exit_code < 0)
			return (exit_code);
		if (!node)
			return (-1);
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}

int	ft_set_data(t_data *data, t_data_parsing *p)
{
	t_token	*token;
	t_node	*node;
	int		exit_code;

	data->envp = p->envp;
	data->first_node = ft_new_node(NULL);
	token = p->first_token;
	if (!p->first_token)
		return (ft_err_pars_message(p, "malloc error\n", -1));
	node = data->first_node;
	exit_code = ft_loop_node_data(node, token);
	if (exit_code < 0)
	{
		if (exit_code == -1)
			return (ft_err_pars_message(p, "malloc error\n", -1));
		return (exit_code);
	}
	return (0);
}
