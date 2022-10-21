/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:44:33 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/21 13:31:34 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*

	La foncion ft_parsing est l'entrée de notre parsing.

	On commence par créer une structure t_data_parsing qui contiendra:

		- Le premier element de la liste des token.
		- Les variables d'environement.

	Ensuite elle va envoyer l'input et la liste au différentes fonction qui va creer cette liste de tokens.
*/


void	ft_print_token_list(t_data_parsing *p) // cette fonction affiche juste la liste des token, elle sert juste au debug
{
	t_token *token;
	
	token = p->first_token;
	while (1)
	{
		printf("VALUE = [%s]\n", token->value);
		if (token->type == WORDS)
			printf("TYPE = [WORDS]\n");
		if (token->type == REDIRECTION)
			printf("TYPE = [REDIRECTION]\n");		
		if (token->type == PIPE)
			printf("TYPE = [PIPE]\n");
		printf("-----------------------------\n");
		if (token->next == NULL)
			break;
		token = token->next;
	}
	ft_free_dp(p);
}

int ft_parsing(char *input, char **envp)
{
	t_data_parsing	*data_p;
	
	data_p = (t_data_parsing *)malloc(sizeof(t_data_parsing));
	if (!data_p)
		return (-1);
	data_p->first_token = NULL;
	data_p->envp = envp;
	if (input && (ft_strncmp(input, "exit", ft_strlen("exit")) == 0)) // Ce bloc de code sert aussi au debugage
	{
		ft_free_dp(data_p);
		exit(0);
	}
	if (ft_set_token_list(data_p, input) == 0)
	{	
		ft_replace_env(data_p);
		ft_delete_quotes(data_p);
		ft_print_token_list(data_p);
	}
	return (0);
}