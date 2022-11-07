/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:31:41 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/07 05:19:29 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	Cette fonction serivra à remplir les noeuds à partir de la liste des tokens.

	En travaux.
	
*/

t_token	*ft_set_one_node(t_node *node, t_token *token)
{
	int	exit_code;
	
	while (1)
	{
		if (ft_is_redirection(token) == 1)
			exit_code = ft_fill_redirection(node, token);
		else if (token->type == WORDS && node->command_name == NULL)
			exit_code = ft_add_command_name(node, token->value);
		else if (token->type == WORDS)
			exit_code = ft_add_arg_node(node, token->value);
		if (exit_code < 0)
		{
			if (exit_code == -1)
				ft_putstr_fd("Minishell: malloc error", 2);
			return (NULL);
		}
		if (token->next == NULL || token->next->type == PIPE)
			break ;
		token = token->next;
	}
	return (token);
}

int	ft_set_data(t_data *data, t_data_parsing *p)
{
	t_token	*token;
	t_node 	*node;

	data->envp = p->envp;
	data->first_node = ft_new_node(NULL);
	token = data->first_token;
	if (!data->first_token)
		return (ft_err_pars_message(p, "malloc error\n", -1));
	node = data->first_node;
	token = ft_set_one_node(node, token);
	while (1)
	{
		if (token->type == PIPE)
		{
			node = ft_new_node(node);
			if (node == NULL)
				return (ft_err_pars_message(p, "malloc error\n", -1));
			token = ft_set_one_node(node, token->next);
			if (token == NULL)
				return (-2);
		}
		if (token->next == NULL)
			break ;
		token = token->next;
	}
	return (0);
}