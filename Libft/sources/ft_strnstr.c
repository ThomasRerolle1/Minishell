/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:24:18 by mravera           #+#    #+#             */
/*   Updated: 2021/12/03 21:47:03 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (haystack[i] != 0 && i < len)
	{
		while (haystack[i + j] == needle[j])
		{
			if (needle[j + 1] == 0 && (i + j < len))
				return (&((char *)haystack)[i]);
			else
				j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
/*
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)	argc;
	char	dest[] = "klsjdhfkjahcocoucoukshjwbonjouhefcoucouoshdhdjlakjsdbonjour";
	char	src[] = "bonjour";
	char	dest2[] = "klsjdhfkjahcocoucoukshjwbonjouhefcoucouoshdhdjlakjsdbonjour";
	char	src2[] = "bonjour";
	size_t	n = (size_t)atoi(argv[1]);

	printf("s1 = [%s]\n", dest);
	printf("s2 = [%s]\n", src);
	printf("vrai = [%s]\n", strnstr(dest, src, n));
	printf("mien = [%s]\n", ft_strnstr(dest2, src2, n));
	return (0);
}
*/
