/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:37:49 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/15 20:32:00 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executor.h"

t_node	*test_find_programm(t_node *first_node, char *command_name)
{
	t_node *node;

	node = ft_new_node(first_node);
	ft_add_command_name(node, command_name);

	return (node);
}

void	test_execve(t_node *node, char **envp)
{
	if (execve(node->path_cmd, node->arg, envp) == -1)
   	 	perror("Could not execve");
}

int main_exec(int argc, char **argv, char **envp)
{
	t_node	*node;
	char	**path_env;
	int i;

	i = 1;
	if (argc < 2)
		return (0);
	path_env = ft_get_path_env(envp);
	node = ft_new_node(NULL);
	ft_add_command_name(node, argv[1]);
	if (ft_find_path_cmd(node, path_env) != 0)
	{
		printf("Command not found: %s\n", node->command_name);
		ft_free_matrice(path_env);
		ft_free_nodes(node);
		exit(0);
	}
	if (argc > 2)
	{
		while (argv[++i])
			ft_add_arg_node(node, argv[i]);
	}
	// printf("Command: %s\n\n", node->command_name);
	// i = 0;
	// while (node->arg[i])
	// {
	// 	printf("arg %d: %s\n", i + 1, node->arg[i]);
	// 	i++;
	// }
	test_execve(node, envp);
	ft_free_matrice(path_env);
	ft_free_nodes(node);
}