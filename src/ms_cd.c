/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:11:14 by mravera           #+#    #+#             */
/*   Updated: 2022/12/07 19:00:19 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_cd(char **str)
{
	if (!str[0])
		return (1);
	if (chdir(str[0]) == -1)
	{
		perror("Error calling cd.\n");
		return (1);
	}
	return (0);
}
