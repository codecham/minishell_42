/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:45:46 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/22 06:13:52 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

void	valid_redirection(t_redir_list *elem)
{
	t_redir_list *tmp;

	tmp = elem;
	while (1)
	{
		if (elem->fd == -1)
		{
			printf("Un fd est pas bon\n");
			exit(0);
		}
		if (elem->next == NULL)
			break;
		elem = elem->next;
	}
}

int		open_file(char *file_name, int type)
{
	int fd;

	fd = -1;
	if (type == OUTFILE)
		fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU);
	if (type == OUTFILE_HAP)
		fd = open(file_name, O_RDWR | O_CREAT | O_APPEND, S_IRWXU);
	if (type == INFILE)
		fd = open(file_name, O_RDONLY);
	return (fd);
}

void	add_redirection(t_node *node, char **argv, int i)
{
	while (argv[i])
	{
		if (argv[i][0] == '>' && argv[i][1] == '\0')
		{
			i++;
			ft_set_redirection(node, OUTFILE, open_file(argv[i], OUTFILE));	
		}
		else if (argv[i][0] == '>')
		{
			i++;
			ft_set_redirection(node, OUTFILE_HAP, open_file(argv[i], OUTFILE_HAP));
		}
		else if (argv[i][0] == '<')
		{
			i++;
			ft_set_redirection(node, INFILE, open_file(argv[i], INFILE));
		}
		i++;
	}
}

int main(int argc, char **argv, char **envp)
{
	t_data *data;
	t_node *node;
	t_node *tmp;
	int		i;

	i = 2;
	if (argc < 2)
		return (0);
	while(argv[i])
	{
		if (argv[i][0] == '>' || argv[i][0] == '<')
		{
			if (ft_strlen(argv[i]) == 2)
			{
				if (argv[i][0] != '>' || argv[i][1] != '>')
				{
					printf("Bad character near redirection\n");
					exit(0);
				}
				
			}
			else if (ft_strlen(argv[i]) != 1)
			{
				printf("Bad character near redirection\n");
				exit(0);
			}
		}
		i++;
	}
	i = 2;
	g_exit_status = 0;
	data = (t_data *)malloc(sizeof(t_data));
	node = ft_new_node(NULL);
	ft_add_command_name(node, argv[1]);
	add_redirection(node, argv, i);
	data->first_node = node;
	data->envp = envp;
	ft_executor(data);
	printf("MMMMH");
	ft_free_nodes(node);
	if (data)
		free(data);
}