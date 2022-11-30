/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:19:17 by mravera           #+#    #+#             */
/*   Updated: 2022/11/29 15:48:20 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <termios.h>
# include <signal.h>
# include <dirent.h>
//# include <readline/history.h>
//# include <readline/readline.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/time.h>
# include <sys/resource.h>
# include "../Libft/libft.h"

//parsing command table
typedef struct s_command
{
	char	*command;
	char	*options;
	char	*arg;
}	t_command;

typedef struct s_admin
{
	t_command	*comlist;
	char		*in;
	char		*out;
	char		*err;
}	t_admin;

//ms_supersplit.c

//ms_utils.c
int	ms_issep(int c);
int	ms_isspace(int c);

#endif
