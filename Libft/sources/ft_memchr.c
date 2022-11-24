/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:38:26 by mravera           #+#    #+#             */
/*   Updated: 2021/11/24 17:58:37 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *) s + i) == (unsigned char) c)
			return ((void *)s + i);
		else
			i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("%s ==> %p\n", argv[1], memchr(argv[1], argv[2][0], atoi(argv[3])));
	printf("%s ==> %p", argv[1], ft_memchr(argv[1], argv[2][0], atoi(argv[3])));
	return (0);
}
*/
