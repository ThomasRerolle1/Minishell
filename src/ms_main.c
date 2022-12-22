/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/12/22 15:58:10 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_admin	adm;

	(void)argc;
	(void)argv;
	ms_bonjour();
	adm.env = ms_create_list_env(envp);
	ms_prompt(&adm);
	return (0);
}

int	ms_prompt(t_admin *adm)
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
		buffer = readline("minishell-0.5$ ");
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
	adm->comtab = ft_split(com, ' ');
	if (adm->comtab[0] && ft_strncmp(adm->comtab[0], "echo", 5) == 0)
		ms_echo(&adm->comtab[1]);
	else if (adm->comtab[0] && ft_strncmp(adm->comtab[0], "pwd", 4) == 0)
		ms_pwd(&adm->comtab[1]);
	else if (adm->comtab[0] && ft_strncmp(adm->comtab[0], "cd", 3) == 0)
		ms_cd(&adm->comtab[1], adm);
	else if (adm->comtab[0] && ft_strncmp(adm->comtab[0], "env", 4) == 0)
		ms_env(adm->env);
	else if (adm->comtab[0] && ft_strncmp(adm->comtab[0], "export", 7) == 0)
		ms_export(&adm->comtab[1], &adm->env);
	else if (adm->comtab[0] && ft_strncmp(adm->comtab[0], "unset", 6) == 0)
		ms_unset(&adm->comtab[1], adm);
	else if (adm->comtab[0] && ft_strncmp(adm->comtab[0], "exit", 5) == 0)
	{
		ms_free_chartab(adm->comtab);
		ft_lstclear(&adm->env, del);
		return (0);
	}
	else if (adm->comtab[0])
		printf("minishell: %s: command not found\n", adm->comtab[0]);
	ms_free_chartab(adm->comtab);
	return (1);
}

void	ms_bonjour(void)
{
	printf("\nYou are using our lite version of bash called Minishell.");
	printf("\nTo update your account to use zsh, please don't run ");
	printf("'chsh -s /bin/zsh' as it will not do anything at all.\n");
	printf("For more details, please don't visit https://support.apple.com\n");
	return ;
}
