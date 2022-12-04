/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/12/04 20:14:04 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

#include <readline/history.h>
#include <readline/readline.h>

int	main(void)
{
	char	*buffer;
	char	**test;

	buffer = NULL;
	while (1)
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		buffer = readline("MyPrompt$=>");
		if (buffer && *buffer)
			add_history(buffer);
		test = ft_split(buffer, ' ');
		if (test[0] && strncmp(test[0], "echo", 5) == 0)
			ms_echo(&test[1]);
		ms_free_chartab(test);
	}
	return (0);
}
