/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:12:46 by mravera           #+#    #+#             */
/*   Updated: 2023/01/04 13:02:46 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

t_list	*ms_create_list_env(char **envp)
{
	t_list	*list_env;
	t_list	*new_elem;
	char	*content;
	int		i;

	i = 0;
	list_env = NULL;
	while (envp[i])
	{
		content = ft_strdup(envp[i]);
		new_elem = ft_lstnew((void *)content);
		ft_lstadd_back(&list_env, new_elem);
		i++;
	}
	ms_setup_env(list_env);
	return (list_env);
}

int	ms_setup_env(t_list *env)
{
	while (env)
	{
		if (ft_strncmp((char *)env->content, "OLDPWD=", 7) == 0)
		{
			free(env->content);
			env->content = ft_strdup("OLDPWD");
		}
		env = env->next;
	}	
	return (1);
}

void	ms_env(t_list *env)
{
	if (!env)
		printf("Error, env seems empty.\n");
	while (env)
	{
		if (ft_strchr((char *)env->content, '='))
			printf("%s\n", (char *)env->content);
		env = env->next;
	}
	return ;
}
