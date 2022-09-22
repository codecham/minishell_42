/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:50:56 by jpaterno          #+#    #+#             */
/*   Updated: 2022/09/20 19:50:58 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"


t_data    *ft_parser(char *str) /*FT principal pour le PARS.*/
{
    int i;
    char **blocs;
    t_node *node;
    t_data *command_line;

    i = 0;
    if (!str[0])
        return (NULL);
    i = 0;
    command_line = malloc(sizeof(t_data) * 1);

    add_history(str);
    blocs = ft_split(str, '|');
    node = ft_new_node(NULL);
    command_line->first_node = node;

    while (blocs[i])
    {
        if (ft_nodes_factory(ft_split(blocs[i], ' '), node) != 0)
            return (NULL);
        node = ft_new_node(node);
        i++;
    }




    return (command_line); /*renvoi un t_data avec ses nodes et path de commande. NULL si erreur*/
}

int    ft_nodes_factory(char **linput, t_node *node) /*rempli le node recu en param, retourne -1 si erreur*/
{   
    int i;

    i = 0;
    ///ft_fusion_quote();
    ft_handle_direction(linput, node);
    
    i = 0;
    if (ft_add_command_name(node, linput[0]) != 0)
        return (-1);
    node->path_cmd = ft_try_cmd(linput[0]);
    if (node->path_cmd == NULL)
        return (-1);
    while (linput[++i])
    {
        if(linput[i][0] == '$')
            linput[i] = ft_get_variable(linput[i]);
        if(ft_isprint(linput[i][0]) == 1 &&  ft_add_arg_node(node, linput[i]) != 0)
            return (-1);
    }
    i = 0;
    return (0);
}

int ft_handle_direction(char **linput, t_node *node) /*Gestion des directions et creations des files*/
{
    int i;
    int type;

    i = 0;
    while (linput[i])
    {
        type = ft_isit_redirection(linput[i]);
        if (type != -1 && linput[i + 1])
        {
            if ((type == 0 || type == 1 || type == 2))
                ft_set_redirection(node, type, open(linput[i + 1], O_CREAT, S_IRUSR, S_IWUSR ,O_RDWR));
            if(type == 3)
                ft_set_redirection(node, type, ft_handle_heredoc(linput[i + 1], i));
            ft_memset(linput[i], 17, ft_strlen(linput[i]));
            ft_memset(linput[i + 1], 17, ft_strlen(linput[i + 1]));
            i++;
        }
        i++;
    }
    return (0);
}

int  ft_handle_heredoc(char *OEF, int id) /*cree la fichier temp et le rempli avec le input du user*/
{
    char *str;
    char *file_name;
    int fd;

    str = NULL;
    file_name = ft_strjoin(ft_itoa(id), "id.tmp_MINISHELL");
    fd = open(file_name, O_CREAT | O_RDWR, 0644);
    if (fd <= 0)
        return (ft_printf("ERROR FD"));
    while (ft_strcmp(str, OEF) != 1)
    {
		ft_putstr_fd(str, fd);
        if (str)
            ft_putchar_fd('\n', fd);
        str = readline(0);
    }
    free(str);
    return (fd);
}



void    *ft_abort_parsing(int error) /*affichages des differents types d'ereur dédié au parser*/
{
    return (NULL);
}