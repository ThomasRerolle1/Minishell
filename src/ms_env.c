/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:04:16 by mravera           #+#    #+#             */
/*   Updated: 2022/12/16 17:17:39 by mravera          ###   ########.fr       */
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
	return (list_env);
}

void	ms_env(t_list *env)
{
	t_list	*first_elem;

	first_elem = env;
	if (!env)
	{
		printf("Error in ms_env\n");
		perror(NULL);
	}
	while (env)
	{
		printf("%s\n", (char *)env->content);
		env = env->next;
	}
	return ;
}
