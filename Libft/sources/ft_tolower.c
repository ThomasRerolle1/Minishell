/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 11:51:25 by mravera           #+#    #+#             */
/*   Updated: 2021/11/24 17:59:43 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	else
		return (c);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("%i ==> %c\n", argv[1][0], tolower(argv[1][0]));
	printf("%i ==> %c", argv[1][0], ft_tolower(argv[1][0]));
	return (0);
}
*/
