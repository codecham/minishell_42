/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:48:19 by jpaterno          #+#    #+#             */
/*   Updated: 2022/09/13 20:48:20 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int ft_check_input(t_node *input, char **envp) /*Check si les commandes sont valides, check de l'existence des fichiers*/
{
    int i;
    int code_error;
    char *path;

    if (input == NULL)
        envp[0] = NULL;
    i = 0;
    while (input != NULL)
    {
        path = ft_try_cmd(input->command_name);
        if (path == NULL)
        {
            ft_printf("commande %s don't exist\n", input->command_name);
            return (-1);
        }
        else
        {
            envp[i] = path;
            input = input->next;
            i++;
        }
    }
    envp[i] = NULL;
    code_error = 0;
    i = -1;
    return (0);
}

char *ft_try_cmd(char *cmd) /*Try la commande sur toutes les listes de PATH*/
{
    char **path;
    char *tmp;
    int i = 0;
    path = ft_split(getenv("PATH"), ':');
    while(path[i])
    {   
        tmp = ft_strjoin(path[i], "/");
        tmp = ft_strjoin(tmp, cmd);
        if (access(tmp, 0) == 0)
            return (tmp);
        free (tmp);
        i++;
    }
    return (NULL);
}
