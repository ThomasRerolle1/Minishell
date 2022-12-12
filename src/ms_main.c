/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/12/12 17:38:57 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

#include <readline/history.h>
#include <readline/readline.h>

int	main(int argc, char **argv, char **envp)
{
	t_admin	*adm;

	adm = NULL;
	(void)envp;
	(void)argc;
	(void)argv;
	ms_prompt(adm);
	return (0);
}

int	ms_prompt(t_admin *adm)
{
	char	*buffer;

	(void)adm;
	while (ft_strncmp(buffer, "exit", 5))
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		buffer = readline("minishell$");
		if (buffer && *buffer)
			add_history(buffer);
		ms_builtin(buffer);
	}
	free(buffer);
	return (1);
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
