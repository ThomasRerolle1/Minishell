/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:11:14 by mravera           #+#    #+#             */
/*   Updated: 2022/12/16 17:17:49 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_cd(char **str, t_admin *adm)
{
	t_list	*env;

	env = adm->env;
	if (!str[0])
		return (1);
	if (chdir(str[0]) == -1)
	{
		perror(NULL);
		return (1);
	}
	while (env)
	{
		if (ft_strncmp((char *)env->content, "PWD=", 4) == 0)
		{
			printf("YIPIKAYE\n");
			printf("old content = %s\n", env->content);
			env->content = (void *)ms_new_pwd(env->content);
			printf("new content = %s\n", env->content);
		}
		env = env->next;
	}
	return (0);
}
