/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_alphaprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:11:15 by mravera           #+#    #+#             */
/*   Updated: 2022/12/26 23:21:20 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_alphaprint(t_list *env)
{
	t_list	*big;

	(void)big;
	return (printf("biginlist = %s\n", (char *)ms_biginlist(env)->content));
	if (env == NULL)
		return (1);
	big = ms_biginlist(env);
	if (env->next == NULL)
		return (1);
}

t_list	*ms_biginlist(t_list *a)
{
	t_list	*b;
	char	*buf;

	if (a == NULL)
		return (NULL);
	b = a->next;
	while (b != NULL)
	{
		buf = ms_trimenv((char *)b->content);
		if (ft_strncmp((char *)b->content, (char *)a->content,
				ft_strlen(buf)) > 0)
			a = b;
		b = b->next;
		free(buf);
	}
	return (a);
}

int	ms_recprint(t_list *top, t_list *env)
{
	(void)top;
	while (env && env->next)
	{
		return (0);
	}
	return (0);
}
