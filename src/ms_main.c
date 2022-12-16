/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/12/13 14:59:50 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

#include <readline/history.h>
#include <readline/readline.h>

#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv, char **envp)
{
	t_admin	*adm;

	adm = NULL;
	(void)envp;
	(void)argc;
	(void)argv;
	ms_prompt(adm, envp);
	return (0);
}

int	ms_prompt(t_admin *adm, char **envp)
{
	char	*buffer;
	int		exit_cmd;

	buffer = NULL;
	(void)adm;
	while (1)
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		buffer = readline("minishell$");
		if (buffer && *buffer)
			add_history(buffer);
		exit_cmd = ms_builtin(buffer, envp);
		if (exit_cmd == 0)
		{
			free(buffer);
			return (0);
		}
	}
	free(buffer);
	return (1);
}

int	ms_builtin(char *com, char **envp)
{
	char	**tab;

	tab = ft_split(com, ' ');
	if (tab[0] && strncmp(tab[0], "echo", 5) == 0)
		ms_echo(&tab[1]);
	else if (tab[0] && strncmp(tab[0], "pwd", 4) == 0)
		ms_pwd(&tab[1]);
	else if (tab[0] && strncmp(tab[0], "cd", 3) == 0)
		ms_cd(&tab[1]);
	else if (tab[0] && strncmp(tab[0], "env", 4) == 0)
		ms_env(envp);
	else if (tab[0] && strncmp(tab[0], "exit", 5) == 0)
	{
		ms_free_chartab(tab);
		return (0);
	}
	else if (tab[0])
		printf("minishell: %s: command not found\n", tab[0]);
	ms_free_chartab(tab);
	return (1);
}
/*
int	main(void)
{
	char	*buffer = NULL;
	size_t	buffer_size = 2048;

	buffer = (char *)malloc(sizeof(char) * buffer_size);
	if (!buffer)
	{
		perror("Malloc failure");
		return (EXIT_FAILURE);
	}
	write(1, "$> ", 3);
	while (getline(&buffer, &buffer_size, stdin) > 0)
	{
		printf("cmd = %s\n", buffer);
		write(1, "$> ", 3);
	}
	printf("Bye\n");
	free(buffer);
}*/
