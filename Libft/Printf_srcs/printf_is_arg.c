/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_is_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:00:25 by mravera           #+#    #+#             */
/*   Updated: 2022/10/08 14:00:43 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	printf_is_arg(const char *obj, va_list lst)
{
	if (*obj == 'c')
		return (printf_is_c(lst));
	else if (*obj == 's')
		return (printf_is_s(lst));
	else if (*obj == 'p')
		return (printf_is_p(lst));
	else if (*obj == 'd')
		return (printf_is_d(lst));
	else if (*obj == 'i')
		return (printf_is_i(lst));
	else if (*obj == 'u')
		return (printf_is_u(lst));
	else if (*obj == 'x')
		return (printf_is_x(lst));
	else if (*obj == 'X')
		return (printf_is_majx(lst));
	else if (*obj == '%')
		return (printf_is_pcent());
	else
		return (0);
}
