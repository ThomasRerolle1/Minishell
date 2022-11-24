/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:33:57 by mravera           #+#    #+#             */
/*   Updated: 2021/12/09 14:13:03 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	if ((dst > src) && (dst <= src + len))
	{
		while (i < len)
		{
			*((unsigned char *)(dst + (len - 1 - i)))
				= *((unsigned char *)(src + (len - 1 - i)));
			i++;
		}
		return (dst);
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
		return (dst);
	}
}
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	//char sResult[] = {67, 68, 67, 68, 69, 0, 45};
	//char sResult2[] = {67, 68, 67, 68, 69, 0, 45};
	printf("memmove    ==> %s\n", memmove(NULL, NULL, 0));
	printf("ft_memmove ==> %s\n", ft_memmove(NULL, NULL, 0));
	return (0);
}
*/
