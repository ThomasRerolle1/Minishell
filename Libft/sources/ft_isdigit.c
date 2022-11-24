/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:07:59 by mravera           #+#    #+#             */
/*   Updated: 2021/11/24 17:58:26 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void) argc;
	printf("%i ==> %i", argv[1][0], ft_isdigit(argv[1][0]));
	return (0);
}
*/
