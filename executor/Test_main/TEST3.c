/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TEST3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:40:14 by dcorenti          #+#    #+#             */
/*   Updated: 2022/09/19 19:55:11 by dcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executor.h"

int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_WRONLY);
	if (fd <= 0)
		return(0);
	dup2(3, 1);
	printf("Ceci est un test\n");
	close(fd);
}