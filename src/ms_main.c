/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/12/08 15:24:35 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

#include <readline/history.h>
#include <readline/readline.h>

int	main(void)
{
	char	*buffer;
	char	**test;
	int		i;

	buffer = NULL;
	while (1)
	{
		i = 0;
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		buffer = readline("minishell$");
		if (!ft_strncmp(buffer, "exit", 5))
		{
			free(buffer);
			return (0);
		}
		if (buffer && *buffer)
			add_history(buffer);
		test = ft_split(buffer, ' ');
		if (test[0] && strncmp(test[0], "echo", 5) == 0)
			ms_echo(&test[1]);
		else if (test[0] && strncmp(test[0], "pwd", 4) == 0)
			ms_pwd(&test[1]);
		else if (test[0] && strncmp(test[0], "cd", 3) == 0)
			ms_cd(&test[1]);
		else if (test[0])
			printf("minishell: %s: command not found\n", test[0]);
		ms_free_chartab(test);
	}
	free(buffer);
	return (0);
}
