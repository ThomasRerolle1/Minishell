/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_supersplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:10:17 by mravera           #+#    #+#             */
/*   Updated: 2022/11/30 15:01:07 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_supersplit(char *str, t_admin adm)
{
	int	i;

	i = 0;
	(void)adm;
	while (str[i])
	{
		if (ms_isspace(str[i]))
			i++;
		if (ft_isprint(str[i]) && !ms_issep(str[i]))
			return (0);
	}
	return (0);
}
