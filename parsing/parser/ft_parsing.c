/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:44:33 by dcorenti          #+#    #+#             */
/*   Updated: 2022/11/09 22:52:41 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*

	La foncion ft_parsing est l'entrée de notre parsing.

	On commence par créer une structure t_data_parsing qui contiendra:

		- Le premier element de la liste des token.
		- Les variables d'environement.

	Ensuite elle va envoyer l'input et la liste au différentes fonction qui va creer cette liste de tokens.

	FONCTION DE DEBBUGAGE A DELETE ET A REMETTRE A LA NORME
*/


void	ft_print_node(t_data *data)
{
	t_node	*node;
	t_redir_list *elem;
	int 	i;
	int		j;
	
	node = data->first_node;
	i = 1;
	j = 0;
	while (1)
	{
		printf("\n------NODE %d------\n", i);
		printf("COMMAND_NAME = [%s]\n", node->command_name);
		if (node->arg != NULL)
		{
			while (node->arg[j])
			{
				printf("ARG %d = [%s]\n", j + 1, node->arg[j]);
				j++;
			}
		}
		j = 0;
		if (node->redirection)
		{
			elem = node->redirection;
			while (1)
			{
				printf("REDIRECTION %d: ", j + 1);
				if (elem->type == INFILE)
					printf("[<]");
				if (elem->type == OUTFILE)
					printf("[>]");
				if (elem->type == OUTFILE_HAP)
					printf("[>>]");
				if (elem->type == HEREDOC)
					printf("[<<]");
				printf(" [%s]\n", elem->file_name);
				if (elem->next == NULL)
					break ;
				elem = elem->next;
				j++;
			}
			j = 0;
		}
		if (node->next == NULL)
			break ;
		node = node->next;
		i++;
	}
}

void	ft_print_token_list(t_data_parsing *p) // cette fonction affiche juste la liste des token, elle sert juste au debug
{
	t_token *token;
	
	token = p->first_token;
	if (p->list_token_size == 0)
		printf("list is empty\n");
	else
	{
		while (1)
		{
			printf("VALUE = [%s]\n", token->value);
			if (token->type == WORDS)
				printf("TYPE = [WORDS]\n");
			if (token->type == INFILE)
			{
				printf("TYPE = [INFILE]\n");
				printf("FILE NAME = [%s]\n", token->red_file_name);
			}
			if (token->type == OUTFILE)
			{
				printf("TYPE = [OUTFILE]\n");
				printf("FILE NAME = [%s]\n", token->red_file_name);
			}
			if (token->type == HEREDOC)
			{
				printf("HEREDOCNAME = %s\n", token->red_file_name);
				printf("TYPE = [HEREDOC]\n");
			}
			if (token->type == OUTFILE_HAP)
			{
				printf("TYPE = [OUTFILE_HAP]\n");
				printf("FILE NAME = [%s]\n", token->red_file_name);
			}
			if (token->type == PIPE)
				printf("TYPE = [PIPE]\n");
			printf("-----------------------------\n");
			if (token->next == NULL)
				break;
			token = token->next;
		}
	}
	printf("list_token_size = %d\n", p->list_token_size);
}

int	ft_parsing(char *input, char **envp)
{
	t_data_parsing	*data_p;
	t_data			*data;

	data_p = (t_data_parsing *)malloc(sizeof(t_data_parsing));
	if (!data_p)
		return (ft_err_pars_message(data_p, "malloc error\n", -1));
	data_p->first_token = NULL;
	data_p->list_token_size = 0;
	data_p->envp = envp;
	if (input && (ft_strncmp(input, "exit", ft_strlen("exit")) == 0)) // Ce bloc de code sert aussi au debugage, il sera a supprimer
	{
		ft_free_dp(data_p);
		exit(0);
	}
	if (ft_create_token_list(data_p, input) < 0)
		return (-1);
	// ft_print_token_list(data_p);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (ft_err_pars_message(data_p, "malloc error\n", -1));
	data->first_token = data_p->first_token;
	data->first_node = NULL;
	if (ft_set_data(data, data_p) < 0)
		return (ft_free_data(data));
	// ft_print_node(data);
	ft_executor(data);
	ft_free_dp(data_p);
	ft_free_data(data);
	return (0);
}
