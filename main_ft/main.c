/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:25:12 by jpaterno          #+#    #+#             */
/*   Updated: 2022/09/13 21:25:13 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
void	read_file(int fd);

/*J'ai fait un main avec une boucle, pour les tests
J'ai gardé le tiens evidemment
Il n'y a aucune difference pour toi, si tu mets des arguments 
c'est ton main a toi qui est lancé*/
void    ft_print_content_parsed(t_data *command_line);

int ft_main2(int argc, char **argv);
int main(int argc, char  **argv)   /// boucle infinie pour les mises en pratiques
{
    int i;
    char *input;
    int check;
    t_data *command_line;

    if (argc > 1 && argv[1][0] != 'X')  
        return (ft_main2(argc, argv));
    input = NULL;
    check = 1;
    i = 0;
    while (1)
    {
        ft_printf("minishell-dcojpa > ");
        input = readline(0);
        command_line = ft_parser(input);
        if (command_line != NULL)
        {
            if (argc == 2)
                ft_print_content_parsed(command_line); /// Lance "./minishell X" pour print le contenu des structs/nodes
            ///ft_executor()
            ///ft_free_nodes(command_line->first_node);
        }
    }
}

int ft_main2(int argc, char **argv) /// main alternatif, ne possede pas de boucle
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
	///read_file(fd);
    return (0);
}

void    ft_print_content_parsed(t_data *command_line) /// print tout le contenu parsé (pour check)
{
    t_node *ptr_n = command_line->first_node;
    char    **env = command_line->envp;
    int     ix = 0;

    while (ptr_n != NULL)
    {
        ft_printf("\n");
        ft_printf("///cmd_name = %s\n", ptr_n->command_name);
        ft_printf("///cmd_path = %s\n", ptr_n->path_cmd);
        while (ptr_n->arg && ptr_n->arg[ix] != NULL)
        {
            ft_printf("arg = %s\n", ptr_n->arg[ix]);
            ix++;
        }
        if (ptr_n->next != NULL)
            ft_printf("next_cmd = %s\n", ptr_n->next->command_name);
        if (ptr_n->previous != NULL)
            ft_printf("previous_cmd = %s\n", ptr_n->previous->command_name);
        if (ptr_n->redirection != NULL)
            ft_printf("redirection type %d vers fd %d\n", ptr_n->redirection->type, ptr_n->redirection->fd);
        ptr_n = ptr_n->next;
        ix = 0;
    }
   /* while (env[ix])
        ft_printf("%s\n", env[ix++]);*/
}