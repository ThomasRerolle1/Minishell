/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 14:07:15 by mravera           #+#    #+#             */
/*   Updated: 2021/11/25 14:41:28 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i] != 0)
			i++;
		return (i);
	}
	while (src[i] != 0 && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	i = 0;
	while (src[i] != 0)
		i++;
	return (i);
}
/*
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	(void)	argc;
	char	src[] = "abcdefghij";
	char	src2[] = "abcdefghij";
	char	dest[] = "12345678901234567890";
	char	dest2[] = "12345678901234567890";
	int 	n = atoi(argv[1]);

	printf("%s ==> ", dest);
	printf("%lu 15eme =>", strlcpy(dest, src, n));
	printf("%c\n", dest[14]);
	printf("%s sizeof(dest)=> %lu\n", dest, sizeof(dest));

	printf("%s ==> ", dest2);
	printf("%zu 15eme =>", ft_strlcpy(dest2, src2, n));
	printf("%c\n", dest2[14]);
	printf("%s sizeof(dest2) => %lu\n", dest2, sizeof(dest2));
	return (0);
}
*/
