/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 13:46:30 by mravera           #+#    #+#             */
/*   Updated: 2022/10/07 22:23:52 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int				ft_printf(const char *obj, ...);

void			*printf_calloc(size_t count, size_t size);
void			printf_putnbr_base(char *res, int nbr, char *base);
void			printf_putnbr_base_ui(char *res, unsigned int nbr, char *base);
void			printf_putnbr_basev(char *r, unsigned long long n, char *b);
unsigned int	printf_strlen_unsigned(char *str);

int				printf_is_arg(const char *obj, va_list lst);
int				printf_is_c(va_list lst);
int				printf_is_s(va_list lst);
int				printf_is_p(va_list lst);
int				printf_is_d(va_list lst);
int				printf_is_i(va_list lst);
int				printf_is_u(va_list lst);
int				printf_is_x(va_list lst);
int				printf_is_majx(va_list lst);
int				printf_is_pcent(void);

#endif
