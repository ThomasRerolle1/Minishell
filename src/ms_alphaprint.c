/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_alphaprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 20:11:15 by mravera           #+#    #+#             */
/*   Updated: 2022/12/29 20:02:12 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_alphaprint(t_list *env)
{
	t_list	*big;
	t_list	*small;

	if (env == NULL)
		return (1);
	big = ms_biginlist(env);
	small = ms_smallinlst(env);
	printf("Biginlist = %s\n", (char *)big->content);
	printf("Smallinlist = %s\n", (char *)small->content);
	ms_recprint(big,env);
	if (env->next == NULL)
		return (1);
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
	big = env;
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
