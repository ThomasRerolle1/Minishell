/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:45:22 by mravera           #+#    #+#             */
/*   Updated: 2022/11/29 15:59:27 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ms_issep(int c)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int	ms_nb_com(char *str)
{
	int	i;
	int	x;
	int	nb;

	nb = 0;
	x = 0;
	i = 0;
	while (str[i])
	{
		if (ms_isspace(str[i])
			i ++;
		if (ft_isalpha(str[i]) && x == 0)
		{
			nb ++;
			x = 1;
		}
		if (ft_isalpha(str[i]))
			i ++;
		

	}
}
