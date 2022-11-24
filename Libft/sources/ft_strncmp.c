/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:35:39 by mravera           #+#    #+#             */
/*   Updated: 2021/11/24 17:59:23 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && i < (n - 1))
	{
		if (s1[i] != s2[i])
			return ((unsigned char) s1[i] - (unsigned char) s2[i]);
		else if (s1[i] == s2[i])
			i++;
	}
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
/*
#include <stdlib.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void)	argc;
	char	*s1 = argv[1];
	char	*s2 = argv[2];
	unsigned int	n = atoi(argv[3]);

	printf("s1 = [%s]\n", s1);
	printf("s2 = [%s]\n", s2);
	printf("tot= [%i]\n", ft_strncmp(s1, s2, n));
	printf("tot= [%i]\n", strncmp(s1, s2, n));
	return (0);
}
*/
