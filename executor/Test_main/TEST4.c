/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:42:12 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/20 18:58:18 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

/*

	main de test pour une commande réguiliere sans redirection ni pipes

	USAGE: ./a.out COMMAND [ARG1] [ARG2]

*/

int main(int argc, char **argv, char **envp)
{
	t_data *data;
	t_node *node;
	t_node *tmp;
	int		i;

	i = 2;
	if (argc < 2)
		return (0);
	g_exit_status = 0;
	data = (t_data *)malloc(sizeof(t_data));
	node = ft_new_node(NULL);
	ft_add_command_name(node, argv[1]);
	while (argv[i])
	{
		ft_add_arg_node(node, argv[i]);
		i++;
	}
	data->first_node = node;
	data->envp = envp;
	ft_executor(data);
	ft_free_nodes(node);
	if (data)
		free(data);
}