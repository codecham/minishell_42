/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:38:15 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/19 15:06:42 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_fill_redirection(t_node *node, t_token *token)
{
	if (ft_set_redirection(node, token->type, -1,
			token->red_file_name) == -1)
		return (-1);
	return (0);
}
