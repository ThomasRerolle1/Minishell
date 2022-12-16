/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/12/16 15:05:44 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_admin	adm;

	(void)argc;
	(void)argv;
	adm.env = ms_create_list_env(envp);
	ms_prompt(&adm);
	return (0);
}

int	ms_prompt(t_admin *adm, char **envp)
{
	char	*buffer;

	buffer = NULL;
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
		if (ms_builtin(buffer, adm) == 0)
		{
			free(buffer);
			return (0);
		}
	}
	free(buffer);
	return (1);
}

int	ms_builtin(char *com, t_admin *adm)
{
	char	**tab;

	tab = ft_split(com, ' ');
	if (tab[0] && ft_strncmp(tab[0], "echo", 5) == 0)
		ms_echo(&tab[1]);
	else if (tab[0] && ft_strncmp(tab[0], "pwd", 4) == 0)
		ms_pwd(&tab[1]);
	else if (tab[0] && ft_strncmp(tab[0], "cd", 3) == 0)
		ms_cd(&tab[1], adm);
	else if (tab[0] && ft_strncmp(tab[0], "env", 4) == 0)
		ms_env(adm->env);
	else if (tab[0] && ft_strncmp(tab[0], "exit", 5) == 0)

	{
		ms_free_chartab(tab);
		ft_lstclear(&adm->env, del);
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