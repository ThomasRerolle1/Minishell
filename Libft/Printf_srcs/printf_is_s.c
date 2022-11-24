/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_is_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:37:15 by mathis            #+#    #+#             */
/*   Updated: 2022/10/08 14:01:22 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_is_s(va_list lst)
{
	char const	*x;
	size_t		i;

	i = 0;
	x = va_arg(lst, const char *);
	if (x == 0)
		x = "(null)";
	while (x[i])
	{
		write(1, &x[i], 1);
		i++;
	}
	return (i);
}
