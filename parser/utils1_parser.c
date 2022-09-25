/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:48:13 by jpaterno          #+#    #+#             */
/*   Updated: 2022/09/13 20:48:15 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
    Je stocke ici les petites fonctions
*/

int ft_isit_redirection(char *str)
{
    int i;

    i = 0;
    if (ft_strcmp(str, ">"))
        return (0);
    if (ft_strcmp(str, ">>"))
        return (1);
    if (ft_strcmp(str, "<"))
        return (2);
    if (ft_strcmp(str, "<<"))
       return (3);
    return (-1);
}

int	ft_strcmp(char *s1, char *s2)
{
    int i;

    if (!s1 | !s2)
        return (0);
    i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (!s1[i] && !s2[i])
        return(1);
	return (0);
}

char    *ft_get_variable(char *str)
{
    int i;
    char *var;
    i = 0;

    var = getenv(str + 1);
    free (str);

    return (var);
}

int ft_fusion_quote(char *str)
{   
    while(*str != '\0')
    {
        if (*str ==  34 && ft_thereis_c(str, 34) == 1)
            str = ft_replace_c(str, 34);
        if (*str ==  39 && ft_thereis_c(str, 39) == 1)
            str = ft_replace_c(str, 39);
        str++;
    }
}

char   *ft_replace_c(char *str, char c)
{
    int i;
    char *tmp;

    tmp = str;

    i = -1;
    str++;
    while (str[++i] != c)
    {
        if (str[i] == ' ')
            str[i] = 18;
        if (str[i] == '|')
            str[i] = 19;
    }
    return (&str[i]);

}