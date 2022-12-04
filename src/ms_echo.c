/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:29:39 by mravera           #+#    #+#             */
/*   Updated: 2022/12/04 20:20:24 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

/*
Prend un tableau de string en entree, check si l'option -n est presente
en premiere position dans le tableau puis ecrit sur la sortie standard chacune
des trings du tableau separee par un espace.
Un retour a la ligne est ajoute a la fin, sauf si l'option -n est detecte.
Un '-' seul est ignore.
*/

int	ms_echo(char **str)
{
	int	i;
	int	opt;

	i = 1;
	opt = 0;
	if (!str || !str[0])
	{
		write(1, "\n", 1);
		return (1);
	}
	if (ft_strncmp(str[0], "-n", 3) == 0)
		opt = 1;
	if (ft_strncmp(str[0], "-n", 3) != 0 && ft_strncmp(str[0], "-", 3) != 0)
		i = 0;
	while (str[i])
	{
		ft_putstr_fd(str[i++], 1);
		if (str[i] != NULL)
			write(1, " ", 1);
	}
	if (opt == 0)
		write(1, "\n", 1);
	return (0);
}
