/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_is_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:36:51 by mathis            #+#    #+#             */
/*   Updated: 2022/10/08 14:01:05 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_is_i(va_list lst)
{
	int		x;
	char	*res;
	size_t	i;

	i = 0;
	res = (char *)printf_calloc(1, 34 * sizeof(char));
	x = va_arg(lst, const int);
	printf_putnbr_base(res, x, "0123456789");
	while (res[i])
	{
		write(1, &res[i], 1);
		i++;
	}
	free(res);
	return (i);
}
