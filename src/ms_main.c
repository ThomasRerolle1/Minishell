/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 21:21:55 by mravera           #+#    #+#             */
/*   Updated: 2023/01/04 18:15:46 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_admin			adm;
	struct termios	termios_s;

	(void)argc;
	(void)argv;
	if (tcgetattr(0, &termios_s) != 0)
		return (1);
	adm.env = ms_create_list_env(envp);
	ms_setsig();
	ms_bonjour(&adm);
	ms_prompt(&adm);
	if (tcsetattr(0, TCSANOW, &termios_s) != 0)
		return (1);
	return (0);
}

int	ms_prompt(t_admin *adm)
{
	char	*buffer;

	buffer = NULL;
	while (adm->loop == 1)
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		buffer = readline("minishell-0.5$ ");
		if (buffer && *buffer)
			add_history(buffer);
		if (!buffer || (ms_builtin(buffer, adm) == 0))
			return (ms_exitfree(buffer, adm, 1));
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
		return (ms_free_chartab(adm->comtab));
	else if (adm->comtab[0])
		printf("minishell: %s: command not found\n", adm->comtab[0]);
	ms_free_chartab(adm->comtab);
	return (1);
}

void	ms_bonjour(t_admin *adm)
{
	adm->loop = 1;
	printf("\nYou are using our lite version of bash called Minishell.");
	printf("\nTo update your account to use zsh, please don't run ");
	printf("'chsh -s /bin/zsh' as it will not do anything at all.\n");
	printf("For more details, please don't visit https://support.apple.com\n");
	return ;
}
