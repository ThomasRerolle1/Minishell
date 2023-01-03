/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_setsig.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 03:06:05 by mravera           #+#    #+#             */
/*   Updated: 2023/01/03 05:40:00 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_setsig(void)
{
	struct termios		termios_p;
	struct sigaction	act_int;
	struct sigaction	act_quit;

	act_int.sa_handler = &ms_int_handler;
	act_quit.sa_handler = SIG_IGN;
	if (tcgetattr(0, &termios_p) != 0)
		return (1);
	termios_p.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, TCSANOW, &termios_p) != 0
		|| sigaction(SIGINT, &act_int, NULL) != 0
		|| sigaction(SIGQUIT, &act_quit, NULL) != 0)
		return (1);
	return (0);
}

void	ms_int_handler(int sign)
{
	if (sign == SIGINT)
	{
		write(2, "\n", 1);
		rl_replace_line("TEST ", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}
