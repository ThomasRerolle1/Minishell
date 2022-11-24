/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:17:24 by mravera           #+#    #+#             */
/*   Updated: 2021/12/07 18:59:52 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*
static int	ft_pow(int nb, int exp)
{
	if (exp == 0)
		return (1);
	if (exp == 1)
		return(nb);
	if (exp < 0)
		return (1 / (ft_pow(nb, -exp)));
	else
		return (nb * ft_pow(nb, exp -1));
}
*/
static size_t	nbint(int x)
{
	size_t		i;
	long int	nb;

	nb = x;
	i = 1;
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 9)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long int	x;
	char		*res;
	size_t		nbi;

	nbi = nbint(n);
	res = malloc(nbi + 1);
	if (!res)
		return (0);
	res[nbi--] = 0;
	x = n;
	if (n < 0)
	{
		res[0] = '-';
		x *= -1;
	}
	while (x > 9)
	{
		res[nbi--] = (x % 10) + '0';
		x /= 10;
	}
	res[nbi] = x + '0';
	return (res);
}
/*
int	main(int argc, char **argv)
{
	int		i = atoi(argv[1]);
	char	*res;

	(void)	argc;
	res = ft_itoa(i);
	printf("%d ==> %s\n", i, res);
	return (0);
}
*/
