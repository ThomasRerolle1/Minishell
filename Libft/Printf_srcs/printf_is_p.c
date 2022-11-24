/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_is_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:37:04 by mathis            #+#    #+#             */
/*   Updated: 2022/10/08 14:01:15 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_is_p(va_list lst)
{
	void	*x;
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)printf_calloc(1, 34 * sizeof(char));
	x = va_arg(lst, void *);
	if (x == 0)
	{
		free(res);
		return (write(1, "(nil)", 5));
	}
	printf_putnbr_basev(res, (unsigned long long) x, "0123456789abcdef");
	write(1, "0", 1);
	write(1, "x", 1);
	while (res[i])
	{
		write(1, &res[i], 1);
		i++;
	}
	free(res);
	return (i + 2);
}
