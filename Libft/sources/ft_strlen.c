/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 19:38:02 by mravera           #+#    #+#             */
/*   Updated: 2021/11/24 17:59:17 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <string.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("%s ==> %lu\n", argv[1], ft_strlen(argv[1]));
	printf("%s ==> %lu", argv[1], strlen(argv[1]));
	return (0);
}
*/
