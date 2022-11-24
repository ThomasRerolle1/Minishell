/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:58:26 by mravera           #+#    #+#             */
/*   Updated: 2021/12/02 02:46:54 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != 0)
	{
		if (s[i] == c % 256)
			return ((char *)s + i);
		else
			i++;
	}
	if (c == 0)
		return ((char *)s + i);
	else
		return (0);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("%s ==> %p\n", argv[1], strchr(argv[1], '\0'));
	printf("%s ==> %p", argv[1], ft_strchr(argv[1], '\0'));
	return (0);
}
*/
