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

    t_node *nodes_list;
    t_data *command_line;
    add_history(str);
    i = 0;
    input = ft_split(str, ' ');
    if (!input[0] || input[0][0] == '\n')
        return (NULL);
    while (input[i])
        i++;
    nodes_list = ft_nodes_factory(input);
    if (nodes_list == NULL)
    {
        ft_printf("PARS PART >>>PARSING has failed\n");
        return (NULL);
    }
    command_line = malloc(sizeof(t_data));
    command_line->envp = malloc(sizeof(char *) * i);
    if (ft_check_input(nodes_list, command_line->envp) == -1)
        return (NULL);
    command_line->first_node = nodes_list;
    return (command_line); /*renvoi un t_data avec ses nodes et path de commande. NULL si erreur*/
}

t_node  *ft_nodes_factory(char **linput) /*FT de creation des nodes (N'est pas déstiné a check le contenu)*/
{
    t_node  *new_node;
    t_node *first_node;
    int     i;
    int     ix;
    int     nb_input;
    int     type;
    

    type = -10;
    ix = 0;
    i = 0;
    new_node = ft_create_node();
    first_node = new_node;
    nb_input = 0;
    while (linput[i])
    {
        while (linput[nb_input++]);
        new_node->arg = malloc(sizeof(char *) * nb_input);
        while (--nb_input)
            new_node->arg[nb_input] = NULL;
        new_node->command_name = linput[i];
        i++;
        while (linput[i] && ft_isit_redirection(linput[i]) == -1)
        {
            new_node->arg[ix++] = linput[i];
            i++;
        }
        ix = 0;
        if (!linput[i])
            break ;
        type = ft_isit_redirection(linput[i]);
        if ((type == 0 || type == 1))
        {
            new_node->redirection = malloc(sizeof(t_redir_list));
            new_node->redirection->type = type;
            if (linput[i + 1])
                new_node->redirection->fd = open(linput[i + 1], O_RDONLY);
            if (new_node->redirection->fd == -1)
            {
                ft_printf("Error, %s doesn't exit\n", linput[i + 1]);
                return (NULL);
            }
            i += 2;
            if (linput[i])
                type = ft_isit_redirection(linput[i]);

        }
        if (type == 2 || type == 3)
            i++;
        if (type == -2)
        {
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


