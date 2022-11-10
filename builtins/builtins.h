/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:30:34 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/26 22:02:14 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "../includes/minishell.h"

# define MAX_PATH_LEN 1024

int		call_builtin(t_node *node);
int		builtin_echo(char **args, int fd_out);
int		builtin_pwd(int fd_out);

void	builtin_cd(char **args, int fd_out);
void	builtin_exit(char **args);

#endif
