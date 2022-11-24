/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:00:44 by mravera           #+#    #+#             */
/*   Updated: 2021/12/02 02:53:57 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = 0;
	while (s[i] != 0)
	{
		if (s[i] == c % 256)
			res = (char *)s + i++;
		else
			i++;
	}
	if (c == 0)
		res = (char *)s + i;
	return (res);
}
/*
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("%s ==> %p\n", argv[1], strrchr(argv[1], '\0'));
	printf("%s ==> %p", argv[1], ft_strrchr(argv[1], '\0'));
	return (0);
}
*/
