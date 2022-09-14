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

int ft_main2(int argc, char **argv);
int main(int argc, char  **argv)   /// boucle infinie pour les mises en pratiques
{
    int i;
    char *input;
    int check;
    t_data *command_line;


    if (argc > 1)  
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
            ft_printf("EXEC PART >>>");
            ///ft_executor()
            ft_printf("\n");
            ///ft_free_nodes(command_line);
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
	read_file(fd);
    return (0);
}