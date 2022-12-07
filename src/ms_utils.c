/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:45:22 by mravera           #+#    #+#             */
/*   Updated: 2022/12/07 17:31:57 by mravera          ###   ########.fr       */
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

int	ms_sizeof_word(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (ms_isspace(str[i]) == 0))
		i++;
	return (i);
}

void	ms_free_chartab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ;
}

int	ms_strlen_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
