/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setvar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:13:58 by mravera           #+#    #+#             */
/*   Updated: 2022/12/21 14:19:17 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

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
		if (ft_strncmp((char *)f->content, trim, ft_strlen(trim) + 1) == 0
			&& ft_strlen(var) >= ft_strlen(trim))
			return (ms_swap_content(f, var, trim, equal));
		if (ft_strncmp((char *)f->content, equal, ft_strlen(equal)) == 0)
			if (ft_strlen(var) > ft_strlen(trim))
				return (ms_swap_content(f, var, trim, equal));
		if (ft_strncmp((char *)f->content, equal, ft_strlen(equal)) == 0)
			return (ms_free_noswap(trim, equal));
		f = f->next;
	}
	free(trim);
	free(equal);
	equal = ft_strdup(var);
	ft_lstadd_back(env, ft_lstnew((void *)equal));
	return (1);
}

char	*ms_trimenv(char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != '=' && str[i] != '\0')
		i++;
	if (i <= 0)
		return (NULL);
	res = malloc(i + 1);
	res[i] = 0;
	i = 0;
	while (str[i] != '=' && str[i] != '\0')
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}

int	ms_free_noswap(char *trim, char *equal)
{
	free(trim);
	free(equal);
	return (1);
}

int	ms_swap_content(t_list *f, char *str, char *trim, char *equal)
{
	free(f->content);
	f->content = (void *)ft_strdup(str);
	free(trim);
	free(equal);
	return (1);
}
