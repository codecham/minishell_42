/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_token_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 22:05:18 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/21 13:35:36 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*
    La fonction ft_set_token_list va créer la liste brut des différent token.

    PARAMERTES: La structure t_data_parsing et l'input de l'utilisateur.

    VALEUR DE RETOUR: renvoie 0 si tout se passe bien et -1 en cas d'erreur de malloc.
*/

int ft_set_separator(t_token *token, char sep)
{
    token->value = ft_realloc_add(token->value, sep);
    if (token->value == NULL)
        return (-1);
    if (sep == '>' || sep == '<')
        token->type = REDIRECTION;
    if (sep == '|')
        token->type = PIPE;
    return (0);
}

int ft_loop_str_token(t_data_parsing *d, t_token *new , char *input, int i)
{
    while (input[i])
    {
        if (input[i] == ' ' | input[i] == '\t')
            i++;
        else
        {
            if (ft_autorized_char(input[i]) == -1)
                return (ft_err_pars_bad_char(d, input[i]));
            if (input[i] == '<' || input[i] == '>' || input[i] == '|')
            {
                if (ft_set_separator(new, input[i]) == -1)
                    return (-1);
                i++;
            }
            else
            {
                i = ft_set_word_token(d, new, input, i);
                if (i == -1)
                    return (-1);
            }
        }
        if (input[i] && input[i] != ' ' && input[i] != '\t')
        {
            new = ft_create_token(new);
            if (!new)
                return(ft_err_pars(d));
        }
    }
    return (0);
}

int ft_set_token_list(t_data_parsing *d, char *input)
{
    t_token *new;
    
    new = ft_create_token(NULL);
    if (!new)
        return (-1);
    d->first_token = new;
    return(ft_loop_str_token(d, new, input, ft_skip_space(input, 0)));
}
