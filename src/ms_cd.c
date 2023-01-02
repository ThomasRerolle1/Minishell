/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:11:14 by mravera           #+#    #+#             */
/*   Updated: 2022/12/27 00:22:01 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_cd(char **str, t_admin *adm)
{
	t_list	*env;
	char	*old;

	env = adm->env;
	if (!str[0])
		return (1);
	old = ms_new_oldpwd(NULL);
	if (chdir(str[0]) == -1)
	{
		perror(NULL);
		free(old);
		return (1);
	}
	return (ms_cd_update_env(env, old));
}

int	ms_cd_update_env(t_list *env, char *old)
{
	int	x;

	x = 0;
	while (env)
	{
		if (ft_strncmp((char *)env->content, "OLDPWD", 7) == 0
			|| ft_strncmp((char *)env->content, "OLDPWD=", 7) == 0)
		{
			free(env->content);
			env->content = old;
			x = 1;
		}
		else if (ft_strncmp((char *)env->content, "PWD", 4) == 0
			|| ft_strncmp((char *)env->content, "PWD=", 4) == 0)
			env->content = (void *)ms_new_pwd(env->content);
		env = env->next;
	}	
	if (x != 1)
		free(old);
	return (0);
}
