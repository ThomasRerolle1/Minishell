/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr_basev.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:06:19 by mathis            #+#    #+#             */
/*   Updated: 2022/10/08 14:01:43 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	printf_putnbr_basev(char *res, unsigned long long nbr, char *base)
{
	unsigned long long	dix;
	unsigned long long	x;
	unsigned long long	i;
	char				temp[34];

	dix = printf_strlen_unsigned(base);
	i = 0;
	if (nbr == 0)
		res[0] = base[0];
	if (nbr == 0)
		return ;
	else
		x = nbr;
	while (x > 0)
	{
		temp[i++] = base[x % dix];
		x = x / dix;
	}
	while (i-- > 0)
		res[x++] = temp[i];
}
