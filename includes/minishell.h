/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:29:59 by dcorenti          #+#    #+#             */
/*   Updated: 2022/06/06 22:33:21 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include "../libft/libft.h"
#include <readline/readline.h> 
#include <readline/history.h> 
#include <termios.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <ast.h>

# define STS_IS_CHILD 0x100
# define STS_HAS_CHILD 0x300
# define STS_INTERRUPT 0x700

//This indentation is to satisfy Norminette's fickle desires.
//We should report that or open a github issue after we finish.
//All hail Norminette. Praised be its whiskers. Blessed be its seat.
int			g_status;


// UTILS
int ft_only_space(char *str);

#endif