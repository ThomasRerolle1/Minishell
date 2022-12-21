/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:23:28 by mravera           #+#    #+#             */
/*   Updated: 2022/12/21 19:00:36 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_unset(char **var, t_list **env)
{
	int	i;

	i = 0;
	if (var[i] == NULL)
		return (1);
	while (var[i])
		ms_unsetone(var[i++], env);
	return (1);
}

int	ms_unsetone(char *var, t_list **env)
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
			|| ft_strncmp((char *)f->content, equal, ft_strlen(equal)) == 0)
		{
			printf("TEST\n");
			ft_lstdelone(f, &del);
			f = f->next;
		}
	}
	return (1);
}
