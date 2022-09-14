/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:48:05 by jpaterno          #+#    #+#             */
/*   Updated: 2022/09/13 20:48:08 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


t_data    *ft_parser(char *str) /*FT principal pour le PARS.*/
{
    int i;
    char **input;
    char *env;

    env = getenv("PATH");
    ft_printf("env = %s\n", env);
    t_node *nodes_list;
    t_data *command_line;
    add_history(str);
    i = 0;
    input = ft_split(str, ' ');
    if (!input[0] || input[0][0] == '\n')
        return (NULL);
    nodes_list = ft_nodes_factory(input);
    if (nodes_list != NULL)
        ft_printf("PARS PART >>>The PARSING is correct\n");
    else
        ft_printf("PARS PART >>>PARSING has failed\n");

    command_line = malloc(sizeof(t_data));
    command_line->first_node = nodes_list;
    return (command_line); /*renvoi un t_data avec ses nodes. NULL si erreur*/
}

t_node  *ft_nodes_factory(char **linput) /*FT de creation des nodes (N'est pas déstiné a check le contenu)*/
{
    t_node  *new_node;
    t_node *first_node;
    int     i;
    int     nb_input;
    int     type;
    

    type = -10;
    i = 0;
    new_node = ft_create_node();
    first_node = new_node;
    nb_input = 0;
    while (linput[i])
    {
        new_node->arg = malloc(sizeof(char *) * nb_input);
        new_node->command_name = linput[i];
        ft_printf("PARS PART >>>command_name == %s\n", linput[i]);
        i++;
        while (linput[i] && ft_isit_redirection(linput[i]) == -1)
        {
            type = ft_isit_redirection(linput[i]);
            new_node->arg[i - 1] = linput[i];
            ft_printf("PARS PART >>>arg == %s\n", linput[i]);
            i++;
        }
        if (linput[i])
            type = ft_isit_redirection(linput[i]);
        if (linput[i] && (type == 0 || type == 1))
        {
            ft_printf("PARS PART >>>redirection == %s\n", linput[i]);
            new_node->redirection = malloc(sizeof(t_redir_list));
            new_node->redirection->type = type;
            if (linput[i + 1])
                new_node->redirection->fd = open(linput[i + 1], O_RDONLY);
            if (new_node->redirection->fd == -1)
            {
                ft_printf("Error, %s doesn't exit\n", linput[i + 1]);
                return (NULL);
            }
            ft_printf("PARS PART >>>redirection FD == %d (file is %s)\n", new_node->redirection->fd, linput[i + 1]);
            i += 2;
        }
        if (linput[i] && (type == 2 || type == 3))
            i++;
        if (linput[i] && type == -2)
        {
            ft_printf("PARS PART >>>pipe == %s\n", linput[i]);
            new_node->next = ft_create_node();
            new_node->next->previous = new_node;
            new_node = new_node->next;
            i++;
        }
    }
    return (first_node);/*renvoi le 1er node. NULL si erreur*/
}

void    *ft_print_error(int error) /*affichages des differents types d'ereur dédié au parser*/
{
    return (NULL);

}


