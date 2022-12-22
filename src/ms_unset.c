/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:23:28 by mravera           #+#    #+#             */
/*   Updated: 2022/12/22 16:45:25 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_unset(char **var, t_admin *adm)
{
	int	i;

	i = 0;
	if (var[i] == NULL)
		return (1);
	while (var[i])
		ms_unsetone(var[i++], adm);
	return (1);
}

int	ms_unsetone(char *var, t_admin *adm)
{
	char	*equal;
	char	*trim;
	t_list	*f;

	f = adm->env;
	trim = ms_trimenv(var);
	equal = ft_strjoin(trim, "=");
	while (f)
	{
		if (ft_strncmp((char *)f->content, trim, ft_strlen(trim) + 1) == 0
			|| ft_strncmp((char *)f->content, equal, ft_strlen(equal)) == 0)
			f = ms_delone_relink(f, adm);
		else
			f = f->next;
	}
	free(trim);
	free(equal);
	return (1);
}

t_list	*ms_delone_relink(t_list *dead, t_admin *adm)
{
	t_list	*f;
	t_list	*res;

	res = dead->next;
	f = adm->env;
	while (f && (f != dead) && (f->next != dead))
		f = f->next;
	if (f == dead)
		adm->env = f->next;
	else if (f->next == dead)
		f->next = dead->next;
	else if (!f)
		printf("Error in lsrelink\n");
	if (f)
		ft_lstdelone(dead, &del);
	return (res);
}
