/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/11/30 17:53:29 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	t_admin	adm;

	i = 0;
	if (argc == 2)
	{
		adm.comtab = ft_split(argv[1], '|');
		len = ft_strlen(*adm.comtab);
		adm.comlist = malloc(sizeof(t_command) * len);
		while (i < len)
		{
			adm.comlist[i].command = adm.comtab[i];
			i++;
		}
		printf("len = %d\n", len);
		i = 0;
		while (adm.comtab[i])
		{
			printf("%d:[%s]\n", i, adm.comlist[i].command);
			i++;
		}
	}
	return (0);
}
