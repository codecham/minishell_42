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

int ft_isit_redirection(char *str)
{
    int i;

    i = 0;

    if(ft_strcmp(str, "|") ||
       ft_strcmp(str, "||"))
       return (-2);

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

    i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
        i++;
    if (!s1[i] && !s2[i])
        return(1);
	return (0);
}