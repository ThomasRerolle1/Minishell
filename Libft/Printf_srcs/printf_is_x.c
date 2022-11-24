/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_is_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:37:24 by mathis            #+#    #+#             */
/*   Updated: 2022/10/08 14:01:31 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_is_x(va_list lst)
{
	unsigned int	x;
	size_t			i;
	char			*res;

	i = 0;
	res = (char *)printf_calloc(1, 34 * sizeof(char));
	x = va_arg(lst, unsigned int);
	printf_putnbr_base_ui(res, x, "0123456789abcdef");
	while (res[i])
	{
		write(1, &res[i], 1);
		i++;
	}
	free(res);
	return (i);
}
