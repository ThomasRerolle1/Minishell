/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_strlen_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 12:04:19 by mathis            #+#    #+#             */
/*   Updated: 2022/10/08 14:01:47 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

unsigned int	printf_strlen_unsigned(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
