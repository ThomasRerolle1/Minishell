/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 14:11:03 by mathis            #+#    #+#             */
/*   Updated: 2021/12/03 21:48:44 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	res = malloc(len + 1);
	if (res == 0)
		return (0);
	while (i <= ft_strlen(s))
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}
