/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:19:17 by mravera           #+#    #+#             */
/*   Updated: 2022/12/16 18:54:36 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL_H
# define FT_MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
//# include <termios.h>
//# include <signal.h>
//# include <dirent.h>
# include <readline/history.h>
# include <readline/readline.h>
//# include <sys/types.h>
//# include <sys/stat.h>
//# include <fcntl.h>
//# include <sys/wait.h>
//# include <sys/stat.h>
//# include <sys/ioctl.h>
//# include <sys/time.h>
//# include <sys/resource.h>
# include "../Libft/libft.h"
//# include <editline/readline.h>

//parsing command table
/*
-> char *command == commande demandee
-> char **arg == liste des arguments demandes
   |-->la fonction doit etre appelee une fois par argument
-> char *options == options demandees
*/
typedef struct s_command
{
	char	*command;
	char	**arg;
}	t_command;

typedef struct s_admin
{
	t_command	*comlist;
	char		**comtab;
	char		*in;
	char		*out;
	char		*err;
	t_list		*env;
}	t_admin;

//ms_main.c
int		ms_prompt(t_admin *adm);
int		ms_builtin(char *com, t_admin *adm);

//ms_supersplit.c
int		ms_supersplit(char *str, t_admin *adm);

//ms_utils.c
int		ms_issep(int c);
int		ms_isspace(int c);
int		ms_sizeof_word(char *str);
void	ms_free_chartab(char **tab);
int		ms_strlen_tab(char **tab);

//ms_utils_ii
char	*ms_new_pwd(char *old_pwd);
char	*ms_new_oldpwd(char *old_pwd);

//builtins
//ms_echo.c
int		ms_echo(char **str);
int		ms_pre_echo(char **str, int *opt);

//ms_pwd.c
int		ms_pwd(char **str);

//ms_cd.c
int		ms_cd(char **str, t_admin *adm);
int		ms_cd_update_env(t_list *env, char *old);

//ms_env.c
t_list	*ms_create_list_env(char **envp);
int		ms_setup_env(t_list *env);
void	ms_env(t_list *env);

#endif
