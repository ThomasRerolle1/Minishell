/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/12/02 18:39:57 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	main(int argc, char **argv)
{
	char	*buffer;

	(void)argc;
	(void)argv;
	buffer = NULL;
	while (1)
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		rl_replace_line
		buffer = readline(NULL);
		if (buffer && *buffer)
			add_history(buffer);
		printf("buffer = %s\n", buffer);
	}
	return (0);
}
