/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 14:53:54 by mravera           #+#    #+#             */
/*   Updated: 2021/11/24 17:58:44 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*((unsigned char *) s1 + i) != *((unsigned char *) s2 + i))
			return (*((unsigned char *) s1 + i) - *((unsigned char *) s2 + i));
		else
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
	char	*s1 = argv[1];
	char	*s2 = argv[2];
	size_t	n = atoi(argv[3]);

	printf("s1 = %s\n", s1);
	printf("s2 = %s\n", s2);
	printf("tot= %i\n", ft_memcmp(s1, s2, n));
	printf("tot= %i\n", memcmp(s1, s2, n));
	return (0);
}
*/
