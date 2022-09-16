/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:39:40 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/16 20:02:05 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

int main(int argc, char **argv, char **envp)
{
	t_data data;
	t_node *node;
	
	if (argc < 2)
		return (0);
	data.first_node = ft_new_node(NULL);
	data.envp = envp;
	node = data.first_node;
	ft_add_command_name(node, argv[1]);
	if (argc == 3)
	{
		node = ft_new_node(node);
		ft_add_command_name(node, argv[2]);
	}
	ft_executor(&data);
	ft_free_nodes(data.first_node);
}