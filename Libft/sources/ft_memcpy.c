/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:17:03 by mravera           #+#    #+#             */
/*   Updated: 2021/12/08 15:12:28 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (src == NULL && dst == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)(dst + i)) = *((unsigned char *)(src + i));
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void) argc;
	char dest1[] = "12345";
	char dest2[] = "12345";
	char src[] = "ouistiti";

	printf("originale ==> %s\n", src);
	printf("memcpy    ==> %s\n", memcpy(dest1, src, atoi(argv[1])));
	printf("ft_memcpy ==> %s\n", ft_memcpy(dest2, src, atoi(argv[1])));
	return (0);
}
*/
