/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 16:25:48 by mravera           #+#    #+#             */
/*   Updated: 2021/11/24 17:57:10 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((unsigned char *)(s + i)) = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	void	*test1;
	void	*test2;
	int		i = 0;
	int		n = 0;
	int		len = strlen(argv[1]);
	(void) argc;

	printf("original ==> %s\n", argv[1]);
	test1 = (void *)argv[1];
	test2 = (void *)argv[1];
	n = atoi(argv[2]);
	bzero(test1, n);
	ft_bzero(test2, n);
	printf("vrai ==> ");
	while (i < len)
	{
		printf("%c", *((unsigned char *)(test1 + i)) + 97);
		i++;
	}
	printf("\nmien ==> ");
	i = 0;
	while (i < len)
	{
		printf("%c", *((unsigned char *)(test2 + i)) + 97);
		i++;
	}
	return (0);
}
*/
