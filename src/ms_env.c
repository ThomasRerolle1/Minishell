/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 16:04:16 by mravera           #+#    #+#             */
/*   Updated: 2022/12/19 21:33:59y mravera          ###   ########.fr       */
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
	t_list	*first_elem;

	first_elem = env;
	if (!env)
	{
		printf("Error in ms_env\n");
		perror(NULL);
	}
	while (env)
	{
		if (ft_strchr((char *)env->content, '='))
			printf("%s\n", (char *)env->content);
		env = env->next;
	}
	return ;
}

int	ms_setvar(char *var, t_list **env)
{
	char	*equal;
	char	*trim;
	t_list	*f;

	f = *env;
	trim = ms_trimenv(var);
	equal = ft_strjoin(trim, "=");
	while (f)
	{
		if (ft_strncmp((char *)f->content, trim, ft_strlen(trim) + 1) == 0)
		{
			free(trim);
			free(equal);
			return (1);
		}
		if (ft_strncmp((char *)f->content, equal, ft_strlen(equal)) == 0)
			return (ms_swap_content(f, var, trim, equal));
		f = f->next;
	}
	free(trim);
	free(equal);
	equal = ft_strdup(var);
	ft_lstadd_back(env, ft_lstnew((void *)equal));
	return (1);
}

int	ms_swap_content(t_list *f, char *str, char *trim, char *equal)
{
	free(trim);
	free(equal);
	free(f->content);
	f->content = (void *)ft_strdup(str);
	return (1);
}
