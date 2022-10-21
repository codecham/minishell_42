/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:15:56 by dcorenti          #+#    #+#             */
/*   Updated: 2022/10/21 14:32:44 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parsing.h"

/*

	La fonction ft_swap_env va remplacer dans la string la variable d'environement par sa valeur.
	
	Il créé une nouvelle string et free l'autre. 

	PARAMETERES:
		- La string dans laquelle remplacer
		- La valeur de la variable
		- L'indice du début de la variable
		- L'indice de fin de la variable

	VALEUR DE RETOUR:
		- Renvoie la nouvelle string avec la variable remplacé par sa valeur
		- Renvoie NULL si malloc échoue
*/

char	*ft_strcat_env(char *old, char *add, int i, int j)
{	
	char	*new;

	i = 0;
	j = -1;
	new = (char *)malloc(sizeof(char) * (ft_strlen(old) + ft_strlen(add) + 1));
	if (!new)
	{
		if (old)
			free(old);
		return (NULL);
	}
	if (old[i] != '\0')
	{
		while (old[i])
		{
			new[i] = old[i];
			i++;
		}
	}
	while (add[++j])
		new[i + j] = add[j];
	new[i + j] = '\0';
	if (old)
		free(old);
	return (new);
}

char	*ft_get_part_string(char *str, int i, int end)
{
	char	*new;

	new = (char *)malloc(sizeof(char));
	if (!new)
		return (NULL);
	new[0] = '\0';
	if (!str)
		return (new);
	while (i < end)
	{
		new = ft_realloc_add(new, str[i]);
		if (!new)
			return (NULL);
		i++;
	}
	return (new);
}

char	*ft_set_final_str(char *first, char *value, char *second)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * 1);
	if (!new)
		return (NULL);
	new[0] = '\0';
	if (ft_strlen(first) > 0)
	{
		new = ft_strcat_env(new, first, 0, -1);
		if (!new)
			return (NULL);
	}
	if (value != NULL)
	{
		new = ft_strcat_env(new, value, 0, -1);
		if (!new)
			return (NULL);
	}
	if (ft_strlen(second) > 0)
	{
		new = ft_strcat_env(new, second, 0, -1);
		if (!new)
			return (NULL);
	}
	return (new);
}

char	*ft_swap_env_token(char *str, char *value, int begin, int end)
{
	char	*first;
	char	*second;
	char	*new;

	first = ft_get_part_string(str, 0, begin);
	second = ft_get_part_string(str, end, ft_strlen(str));
	if (!first || !second)
	{
		if (first)
			free(first);
		if (second)
			free(second);
		return (NULL);
	}
	new = ft_set_final_str(first, value, second);
	free(first);
	free(second);
	if (!new)
		return (NULL);
	return (new);
}
