/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/12/09 17:21:48 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

#include <readline/history.h>
#include <readline/readline.h>

int	main(int argc, char **argv, char **envp)
{
	char	*buffer;
	int		i;

	buffer = NULL;
	(void)argc;
	(void)argv;
	while (*envp)
		printf("%s\n", *envp++);
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
		ms_builtin(buffer);
	}
	free(buffer);
	return (0);
}

void	ms_builtin(char *com)
{
	char	**tab;

	tab = ft_split(com, ' ');
	if (tab[0] && strncmp(tab[0], "echo", 5) == 0)
		ms_echo(&tab[1]);
	else if (tab[0] && strncmp(tab[0], "pwd", 4) == 0)
		ms_pwd(&tab[1]);
	else if (tab[0] && strncmp(tab[0], "cd", 3) == 0)
		ms_cd(&tab[1]);
	else if (tab[0])
		printf("minishell: %s: command not found\n", tab[0]);
	ms_free_chartab(tab);
	return ;
}
