/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:47:27 by mravera           #+#    #+#             */
/*   Updated: 2021/12/10 15:13:12 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	a = n % 10 + '0';
	write(fd, &a, 1);
	return ;
}
/*
#include <stdlib.h>

int main(int argc, char **argv)
{
	(void)	argc;

	ft_putnbr_fd(atoi(argv[1]), 1);
	return (0);
}
*/
