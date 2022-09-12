/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 20:10:46 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/12 20:18:27 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../node/node.h"
# include "../signals/signals.h" 

struct	s_node;

typedef struct s_data
{
	struct s_node	*first_node;
	char			**envp;

}	t_data;

#endif