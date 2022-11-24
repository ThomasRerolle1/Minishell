/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 14:20:30 by mravera           #+#    #+#             */
/*   Updated: 2021/11/24 17:57:52 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("%i ==> %i\n", argv[1][0], ft_isascii(argv[1][0]));
	printf("%i ==> %i", argv[1][0], isascii(argv[1][0]));
	return (0);
}
*/
