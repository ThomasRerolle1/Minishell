/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:19:17 by mravera           #+#    #+#             */
/*   Updated: 2022/12/22 16:03:52 by mravera          ###   ########.fr       */
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
# define TOKEN_NULL 0
# define TOKEN_SPACE 1
# define TOKEN_REDIRECTION 2
# define TOKEN_DOUBLE_QUOTE 3
# define TOKEN_SINGLE_QUOTE 4
# define TOKEN_WORD 5

typedef struct s_token{
	void	*content;
	char	*raw_content;
	int		type_of_content;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;


typedef struct s_command
{
	char	*command;
	char	**arg;
	struct	s_command	*next;
	struct	s_command	*prev;
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
void	ms_bonjour(void);

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

//ms_setvar.c
int		ms_setvar(char *var, t_list **env);
char	*ms_trimenv(char *str);
int		ms_free_noswap(char *trim, char *equal);
int		ms_swap_content(t_list *f, char *str, char *trim, char *equal);

//ms_export.c
int		ms_export(char **var, t_list **env);
int		ms_display_all(t_list *env);
int		ms_check_identifier(char *str);
char	*ms_arg_inquote(char *str);

//ms_unset.c
int		ms_unset(char **var, t_admin *adm);
int		ms_unsetone(char *var, t_admin *adm);
t_list	*ms_delone_relink(t_list *dead, t_admin *adm);

//ft_get_substr.c
int		is_separator(char c);
char	*ft_substr_word_space(char *line);
char	*ft_substr_quote(char *line);
char	*ft_substr_redirection(char *line);
char	*ft_get_substr(char *line);

//ms_token.c
t_token	*create_token(void);
void	fill_token(t_token *token, char *substr);
t_token	*token_last(t_token *first_token);
void	token_add_back(t_token **first_token, t_token *new_token);
void	create_fill_add_token(t_token **first_token_in_list, char *raw_content);

//ms_truncate_line.c
char	*ms_truncate_line(char *line, char *substr);
#endif
