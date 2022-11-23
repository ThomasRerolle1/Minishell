/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/11/23 16:19:24 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_minishell.h"

int	main(void)
{
	char	*texte;
	size_t	taille;

	taille = 64;
	texte = (char *)calloc(sizeof(char), taille);
	if (texte == NULL)
	{
		perror("calloc error\n");
		return (0);
	}
	printf("$minishell_prompt> ");
	while (getline(&texte, &taille, stdin) > 0)
	{
		printf("le texte entre est %s(taille = %zu)\n", texte, taille);
		printf("$minishell_prompt> ");
	}
	return (0);
}
