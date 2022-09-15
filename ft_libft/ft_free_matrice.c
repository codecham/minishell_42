/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 20:24:12 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/15 20:28:35 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void 	ft_free_matrice(char **matrice)
{
	int i;

	i = 0;
	if (!matrice)
		return ;
	while (matrice[i])
	{
		if (matrice[i])
			free(matrice[i]);
			i++;
	}
	if (matrice)
		free(matrice);
}