/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:28:58 by mravera           #+#    #+#             */
/*   Updated: 2021/11/24 17:59:04 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)(b + i)) = (unsigned char) c;
		i++;
	}
	return (b);
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("%s ==> %p\n", argv[1], memset(argv[1], argv[2][0], atoi(argv[3])));
	printf("%s ==> %p", argv[1], ft_memset(argv[1], argv[2][0], atoi(argv[3])));
	return (0);
}
*/
