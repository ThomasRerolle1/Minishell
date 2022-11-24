/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:39:28 by mravera           #+#    #+#             */
/*   Updated: 2021/11/24 17:57:44 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91)
		|| (c > 96 && c < 123))
		return (1);
	else
		return (0);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("%i ==> %i", argv[1][0], ft_isalpha(argv[1][0]));
	return (0);
}
*/
