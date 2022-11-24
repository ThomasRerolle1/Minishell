/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_putnbr_base_ui.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:58:18 by mathis            #+#    #+#             */
/*   Updated: 2022/10/08 14:01:35 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	printf_putnbr_base_ui(char *res, unsigned int nbr, char *base)
{
	unsigned int	dix;
	unsigned int	x;
	unsigned int	i;
	char			temp[34];

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
