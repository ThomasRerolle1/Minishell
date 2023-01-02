/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_alphaprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:58:04 by mravera           #+#    #+#             */
/*   Updated: 2023/01/02 17:25:23 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

void	cmpall(t_list *env)
{
	t_list	*t;
	t_list	*origin;

	origin = env;
	t = origin;
	while (env)
	{
		while (t)
		{
			printf("lstcmp(%s, %s) = %d\n", (char *)env->content,
				(char *)t->content, ms_lstcomp(env, t));
			t = t->next;
		}
		t = origin;
		env = env->next;
	}
}

int	ms_alphaprint(t_list *env)
{
	t_list	*big;

	if (env == NULL)
		return (1);
	big = ms_biginlist(env);
	ms_recprint(big, env);
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

t_list	*ms_smallinlst(t_list *a)
{
	t_list	*b;

	if (a == NULL)
		return (NULL);
	b = a->next;
	while (b != NULL)
	{
		if (ms_lstcomp(b, a) == -1)
			a = b;
		b = b->next;
	}
	return (a);
}	

int	ms_recprint(t_list *top, t_list *env)
{
	t_list	*t;
	t_list	*big;

	t = env;
	big = t;
	while (t && (ms_lstcomp(t, top) >= 0))
	{
		big = t;
		t = t->next;
	}
	if (t)
		big = t;
	while (t)
	{
		if (ms_lstcomp(t, big) == 1
			&& ms_lstcomp(t, top) == -1)
			big = t;
		t = t->next;
	}
	if (ms_smallinlst(env) != top)
		ms_recprint(big, env);
	ms_display_one(top);
	return (0);
}
