/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_calloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 21:59:30 by mravera           #+#    #+#             */
/*   Updated: 2022/10/08 14:00:46 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*printf_calloc(size_t count, size_t size)
{
	size_t	tot;
	void	*res;
	size_t	i;

	i = 0;
	tot = count * size;
	res = malloc(tot);
	if (res == 0)
		return (0);
	if (tot > 2147483647)
		return (0);
	while (i < tot)
		((char *)res)[i++] = 0;
	return (res);
}
