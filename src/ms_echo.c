/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 18:29:39 by mravera           #+#    #+#             */
/*   Updated: 2022/12/08 15:24:32 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

//Prend un tableau de string en entree, check si l'option -n est presente
//en premiere position dans le tableau puis ecrit sur la sortie standard chacune
//des trings du tableau separee par un espace.
//la repetition de -n est accepte ainsi que qu'un nombre arbitraire de n.
//Exemple (-nnn -n -n).
//Un retour a la ligne est ajoute a la fin, sauf si l'option -n est detecte.
//ligne suivante fausse dans bash, vraie dans zsh.
//Le premier '-' seul est ignore puis la fonction n'accepte plus d'option.

int	ms_echo(char **str)
{
	int	i;
	int	opt;

	i = 0;
	opt = 0;
	if (!str || !str[0])
	{
		write(1, "\n", 1);
		return (1);
	}
	i = ms_pre_echo(str, &opt);
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

int	ms_pre_echo(char **str, int *opt)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		if ((str[i][j] == '-') && (str[i][j + 1] == 'n'))
		{
			j++;
			while (str[i][j] && (str[i][j] == 'n'))
				j++;
		}
		if (str[i][j] == '\0')
			*opt = 1;
		else
			return (i);
		i++;
	}
	return (i);
}
