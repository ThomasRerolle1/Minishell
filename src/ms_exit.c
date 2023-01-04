/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:46:13 by mravera           #+#    #+#             */
/*   Updated: 2023/01/04 18:14:33 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_exit(t_admin *adm, int exit)
{
	if (exit)
		printf("exit\n");
	adm->loop = 0;
	ft_lstclear(&adm->env, &free);
	return (0);
}

int	ms_exitfree(char *tofree, t_admin *adm, int exit)
{
	free(tofree);
	if (exit)
		printf("exit\n");
	adm->loop = 0;
	ft_lstclear(&adm->env, &free);
	return (0);
}
