/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST_FUNCTION.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 21:13:20 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/11 20:50:29 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"
#include <fcntl.h>

/*
	Ceci est un programme de test pour générer des structures. Cela te premet de voir à quoi ressemble la strcture et cela me permet à moi de générer des structure pour tester mes fonctions.

	Il s'utilise avec comme argument d'entrée un fichier (tu as un exemple de fichier avec TEST_FILE.txt)
*/

char	*remove_new_line(char *line)
{
	char *new;
	int i;

	if (!line)
		return (line) ;
	i = 0;
	while(line[i])
		i++;
	if (line[i - 1] != '\n')
		return (line);
	i = 0;
	new = (char *)malloc(sizeof(char) * ft_strlen(line) - 1);
	while (line[i] != '\n')
	{
		new[i] = line[i];
		i++;
	}
	new[i] = '\0';
	free(line);
	return (new);
}

void 	print_nodes(t_node *node)
{
	int i;
	int j;
	t_redir_list *li;
	t_node *tmp;

	i = 0;
	j = 0;
	tmp = node;
	if (!node)
		return ;
	while (tmp != NULL)
	{
		printf("----------------------------------\n");
		printf("node %d:\n\n", i + 1);
		if (tmp->command_name)
			printf("COMMAND_NAME = [%s]\n", tmp->command_name);
		if (tmp->arg)
		{
			while (tmp->arg[j])
			{
				printf("ARG %d = [%s]\n", j + 1, tmp->arg[j]);
				j++;
			}
			j = 0;
		}
		if (tmp->redirection)
		{
			li = tmp->redirection;
			while (li != NULL)
			{
				printf("REDIRECTION %d = ", j + 1);
				if (li->type == INFILE)
					printf("> ");
				else if (li->type == OUTFILE)
					printf("< ");
				else if (li->type == INFILE_HAP)
					printf(">> ");
				else if (li->type == HEREDOC)
					printf("<< ");
				printf("- fd = %d\n", li->fd);
				j++;
				li = li->next;
			}
			j = 0;
		}
		printf("----------------------------------\n\n");
		i++;
		tmp = tmp->next;
	}
}

void	test_add_arg(t_node *node, char *line)
{
	ft_add_arg_node(node, &line[3]);
	// printf("ok add arg 2\n");
}

void	test_add_list(t_node *node, char *line)
{
	int i;
	static int fd;

	i = 3;
	fd = 10;
	if (line[i] == '>')
	{
		if (line[i + 1] == '>')
			ft_set_redirection(node, INFILE_HAP, fd);
		else
			ft_set_redirection(node, INFILE, fd);

	}
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
			ft_set_redirection(node, HEREDOC, fd);
		else
			ft_set_redirection(node, OUTFILE, fd);
	}
	fd++;
}

void	test_add_command(t_node *node, char *line)
{
	node->command_name = ft_strdup(line);
}

void	read_file(int fd)
{
	t_node 	*node = NULL;
	t_node 	*first_node = NULL;
	char 	*line;
	int		i = 1;
	
	line = get_next_line(fd);
	line = remove_new_line(line);
	if (line == NULL)
		return ;
	while (line != NULL)
	{
		if (ft_strlen(line) != 0)
		{
			if (line[0] == 'C')
			{
				if (!node)
				{
					node = ft_new_node(node);
					first_node = node;
					test_add_command(node, &line[3]);
				}
				else
				{
					node->next = ft_new_node(node);
					node = node->next;
					test_add_command(node, &line[3]);
				}
			}
			else if (line[0] == 'A')
				test_add_arg(node, line);
			else if (line[0] == 'R')
				test_add_list(node, line);
		}
		if (line)
			free(line);
		line = get_next_line(fd);
		line = remove_new_line(line);
		i++;
	}
	print_nodes(first_node);
	ft_free_nodes(first_node);
}


/// Deplacé dams main_ft

/*int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		printf("WRONG USAGE!\n");
		printf("USAGE: ./a.out FILE_NAME\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("WRONG FILE NAME\n");
		exit(0);
	}
	read_file(fd);
}*/