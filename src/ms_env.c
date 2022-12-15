/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:04:16 by mravera           #+#    #+#             */
/*   Updated: 2022/12/15 16:05:31 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

t_list	*create_list_env(char **envp)
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
	new_elem->next = NULL;
	return (list_env);
}

void	ms_env(char **envp)
{
	t_list	*list_env;
	t_list	*first_elem;

	if (!envp)
	{
		printf("coucou");
		perror(NULL);
	}
	printf("coucou");
	list_env = create_list_env(envp);
	first_elem = list_env;
	while (list_env)
	{
		printf("%s\n", (char *)list_env->content);
		list_env = list_env->next;
	}
	ft_lstclear(&first_elem, del);
	return ;
}
