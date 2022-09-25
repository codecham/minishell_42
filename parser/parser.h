/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:50:56 by jpaterno          #+#    #+#             */
/*   Updated: 2022/09/16 19:00:48 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "../includes/minishell.h"

struct	s_node;

typedef struct	s_data
{
	struct s_node	*first_node;
	char			**envp;
	char			**path_env;

}				t_data;

int			ft_check_input(t_node *input, char **envp);
t_data      *ft_parser(char *str);
int    ft_nodes_factory(char **linput, t_node *node);
void    *ft_abort_parsing(int error);
int         ft_isit_redirection(char *str);
int         ft_strcmp(char *s1, char *s2);
char		*ft_try_cmd(char *cmd);
int ft_handle_direction(char **linput, t_node *node);
int  ft_handle_heredoc(char *OEF, int id);
char    *ft_get_variable(char *str);
int ft_thereis_c(char *str, char c);
int ft_fusion_quote(char *str);
void    ft_get_real_value(char **linput);
char   *ft_replace_c(char *str, char c);



#endif