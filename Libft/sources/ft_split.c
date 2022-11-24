/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:56:25 by mravera           #+#    #+#             */
/*   Updated: 2021/12/10 15:17:07 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**freetab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static size_t	nextchar(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

static size_t	nbword(char const *s, char c)
{
	size_t	i;

	i = 0;
	if (ft_strlen(s) == 0)
		return (0);
	if (s[i] != 0 && s[i] != c)
		i++;
	s++;
	while (*s)
	{
		if (*s != c && *(s - 1) == c)
			i++;
		s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**res;

	if (!s)
		return (0);
	i = 0;
	res = malloc(sizeof (char *) * (nbword(s, c) + 1));
	if (!res)
		return (0);
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			res[i] = ft_substr(s, 0, nextchar(s, c));
			if (!res[i])
				return (freetab(res));
			s += nextchar(s, c);
			i++;
		}
	}
	res[i] = NULL;
	return (res);
}
/*
int	main(int argc, char **argv)
{
	(void) argc;
	char *s1 = argv[1];
	char c = *argv[2];
	char **res = ft_split(s1, c);

	printf("1 = %s\n", res[0]);
	printf("2 = %s\n", res[1]);
	//printf("3 = %s\n", res[2]);
	//printf("4 = %s\n", res[3]);

  return 0;
}
*/
