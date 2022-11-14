/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_env_var.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduvivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 20:37:46 by dduvivie          #+#    #+#             */
/*   Updated: 2022/11/13 01:30:37 by dduvivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../builtins.h"
#include "../../includes/minishell.h"

/*
Create a string array, malloc memory, and copy the content of *str,
but copy only characters found before the first '=' sign.
Paramater example: "NEW_VAR=Hello"
Return value:	   "NEW_VAR"
*/
char	*ft_cpy_env_key(char *str)
{
	int		size;
	int		i;
	char	*key;

	size = 0;
	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0' && str[i] != '=')
	{
		size++;
		i++;
	}
	if (size == 0)
		return (NULL);
	key = (char *)malloc((size + 1) * sizeof(char));
	if (!key)
		return (NULL);
	ft_strlcpy(key, str, size + 1);
	return (key);
}

/*
Create a string array, malloc memory, and copy the content of *str,
but copy only characters found after the first '=' sign.
Paramater example: "NEW_VAR=Hello"
Return value:	   "Hello"
 */
char	*ft_cpy_env_val(char *str)
{
	int		size;
	int		i;
	char	*value;

	if (!str)
		return (NULL);
	while (*str != '\0' && *str != '=')
		str++;
	if (*str == '=')
		str++;
	i = 0;
	size = 0;
	while (str[i] != '\0')
	{
		size++;
		i++;
	}
	value = (char *)malloc((size + 1) * sizeof(char));
	if (!value)
		return (NULL);
	ft_strlcpy(value, str, size + 1);
	return (value);
}
