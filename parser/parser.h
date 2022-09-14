/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaterno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:50:56 by jpaterno          #+#    #+#             */
/*   Updated: 2022/09/13 20:50:57 by jpaterno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "../includes/minishell.h"

struct	s_node;

typedef struct s_data
{
	struct s_node	*first_node;
	char			**envp;

}	t_data;

int         ft_check_input(char *input);
t_data      *ft_parser(char *str);
t_node      *ft_nodes_factory(char **input_splited);
void        *ft_print_error(int error);
int         ft_isit_redirection(char *str);
int         ft_strcmp(char *s1, char *s2);



#endif