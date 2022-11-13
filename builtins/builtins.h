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

typedef struct s_env
{
	char			*value;
	char			*key;
	struct s_env	*next;
}	t_env;

/*
-------------------------------BUILTINS-----------------------------------------
*/

int		ft_call_builtin(t_node *node, t_env *env);
int		ft_builtin_echo(char **args, int fd_out);
int		ft_builtin_pwd(int fd_out);
int		ft_builtin_cd(char *dir);
int		ft_builtin_env(int fd_out, t_env *env);
int		ft_builtin_export(char **args, t_env *env);

int		ft_builtin_unset(char **args, int fd_out, char **envp);
void	ft_builtin_exit(char **args);

/*
----------------------------------ENV-----------------------------------------
*/
t_env	*ft_get_env_var_list(char **envp);
t_env	*ft_add_env_var(t_env *first_env_var, t_env *env_var);
t_env	*ft_new_env_var(char *str);
char	*ft_cpy_env_key(char *str);
char	*ft_cpy_env_val(char *str);
void	ft_free_env_var_list(t_env *env_var);
void	ft_free_env_var(t_env *env_var);


#endif
