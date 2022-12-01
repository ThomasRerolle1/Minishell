/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:32:50 by mravera           #+#    #+#             */
/*   Updated: 2022/12/01 17:42:55 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	main(int argc, char **argv)
{
	int		i;
	int		len;
	t_admin	adm;

	i = 0;
	len = 0;
	if (argc == 2)
	{
		adm.comtab = ft_split(argv[1], '|');
		while (adm.comtab[len])
			len++;
		adm.comlist = malloc(sizeof(t_command) * len);
		while (i < len)
		{
			adm.comlist[i].command = &(adm.comtab[i]);
			i++;
		}
		i = 0;
		while (adm.comtab[i])
		{
			printf("%d:[%s]\n", i, *(adm.comlist[i].command));
			i++;
		}
	}
	return (0);
}

/* A static variable for holding the line. */
static char *line_read = (char *)NULL;

/* Read a string, and return a pointer to it.  Returns NULL on EOF. */
char *
rl_gets ()
{
  /* If the buffer has already been allocated, return the memory
     to the free pool. */
  if (line_read)
    {
      free (line_read);
      line_read = (char *)NULL;
    }

  /* Get a line from the user. */
  line_read = readline ("");

  /* If the line has any text in it, save it on the history. */
  if (line_read && *line_read)
    add_history (line_read);

  return (line_read);
}
