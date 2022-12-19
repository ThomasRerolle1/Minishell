/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:00:54 by mravera           #+#    #+#             */
/*   Updated: 2022/12/19 20:54:07 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_export(char **var, t_list **env)
{
	int		i;

	i = 0;
	if (var[i] == NULL)
		return (ms_display_all(*env));
	while (var[i])
	{
		ms_setvar(var[i], env);
		i++;
	}
	return (1);
}

int	ms_display_all(t_list *env)
{
	while (env)
	{
		printf("%s\n", (char *)env->content);
		env = env->next;
	}
	return (1);
}
