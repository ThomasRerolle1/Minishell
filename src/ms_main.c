/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/11/24 15:12:12 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"
#include <stdio.h>
#include <stdlib.h>
/*
int	main(void)
{
	char	**tab;
	char	*s;
	int		i;
	size_t	taille;

	taille = 256;
	printf("$minishell_prompt> ");
	while (getline(&s, &taille, stdin) > 0)
	{
		tab = ft_split(s, ' ');
		printf("splitting in tab %p\n", tab);
		i = 0;
		while (tab[i])
		{
			printf("Tab[%p] = %s\n", tab[i], tab[i]);
			i++;
		}
		while (--i >= 0)
		{
			printf("freeing %p\n", tab[i]);
			free(tab[i]);
		}
		printf("freeing %p\n", tab);
		free(tab);
		printf("$minishell_prompt> ");
	}
	return (0);
}
*/
int	main(void)
{
	char	*buffer = NULL;
	size_t	buffer_size = 2048;

	buffer = (char *)malloc(sizeof(char) * buffer_size);
	if (!buffer)
	{
		perror("Malloc failure");
		return (EXIT_FAILURE);
	}
	write(1, "$> ", 3);
	while (getline(&buffer, &buffer_size, stdin) > 0)
	{
		printf("cmd = %s\n", buffer);
		write(1, "$> ", 3);
	}
	printf("Bye\n");
	free(buffer);
}
