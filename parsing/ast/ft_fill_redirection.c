/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 22:38:15 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/07 18:43:51 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	La fonction ft_fill_redireciton va ouvrir le fichier correspondant 
	à la redireciton et va l'ajouter à la liste des redrection de la node.

	PARAMETRES:
		- La node à laquelle ajouter la redirection
		- Le token contenant la redirection
	
	VALEUR DE RETOUR:
		- Retourne 0 si tout se passe bien
		- Retourne -1 si une erreur de malloc est trouvée
		- Retourne -2 et imprime le message en cas d'erreur
*/

int	ft_err_files_message(char *name, char *message)
{
	ft_putstr_fd("Minishell: ", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(message, 2);
	return (-2);
}

int	ft_open_file_fd(t_token *token, char *file_name, int type)
{
	if (type == INFILE && (access(file_name, F_OK) == 0))
		token->fd = open(file_name, O_RDONLY);
	else if (type == INFILE || type == HEREDOC)
		token->fd = open(file_name, O_RDONLY | O_CREAT | O_TRUNC, S_IRWXU);
	else if (type == OUTFILE)
		token->fd = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
	else if (type == OUTFILE_HAP)
		token->fd = open(file_name, O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);
	if (token->fd == -1)
		return (-2);
	return (0);
}

int	ft_check_access(t_token *token)
{
	if (access(token->red_file_name, F_OK) == 0)
	{
		if (token->type == OUTFILE || token->type == OUTFILE_HAP)
		{
			if (access(token->red_file_name, W_OK) != 0)
				return (-1);
		}
		else if (token->type == INFILE)
		{
			if (access(token->red_file_name, R_OK) != 0)
				return (-1);
		}
	}
	return (0);
}

int	ft_fill_redirection(t_node *node, t_token *token)
{
	if (token->type == OUTFILE || token->type == OUTFILE_HAP)
	{
		if (ft_is_directory(token->red_file_name) == 1)
			return (ft_err_files_message(token->red_file_name,
					"Is a directory"));
	}
	if (ft_check_access(token) == -1)
		return (ft_err_files_message(token->red_file_name,
				"Permission denied"));
	if (ft_open_file_fd(token, token->red_file_name, token->type) < 0)
		return (ft_err_files_message(token->red_file_name, "Can't open file"));
	if (ft_set_redirection(node, token->type, token->fd,
			token->red_file_name) == -1)
		return (-1);
	return (0);
}
