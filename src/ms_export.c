/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 17:00:54 by mravera           #+#    #+#             */
/*   Updated: 2023/01/02 17:27:39 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_export(char **var, t_list **env)
{
	int		i;

	i = 0;
	if (var[i] == NULL)
		return (ms_alphaprint(*env));
	while (var[i])
	{
		if (!ms_check_identifier(var[i]))
			printf("minishell: export: not a valid identifier\n");
		else
			ms_setvar(var[i], env);
		i++;
	}
	return (1);
}

int	ms_display_all(t_list *env)
{
	char	*buf;

	while (env)
	{
		if (!ft_strchr(env->content, '='))
			printf("declare -x %s\n", (char *)env->content);
		else
		{
			buf = ms_arg_inquote((char *)env->content);
			printf("declare -x %s\n", buf);
			if (buf != NULL)
				free(buf);
		}
		env = env->next;
	}
	return (1);
}

int	ms_display_one(t_list *env)
{
	char	*buf;

	if (!ft_strchr(env->content, '='))
		printf("declare -x %s\n", (char *)env->content);
	else
	{
		buf = ms_arg_inquote((char *)env->content);
		printf("declare -x %s\n", buf);
		if (buf != NULL)
			free(buf);
	}
	return (1);
}

int	ms_check_identifier(char *str)
{
	if (ft_isalpha(*str) || (*str == '_'))
		return (1);
	return (0);
}

char	*ms_arg_inquote(char *str)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	res = malloc(sizeof(char) * ft_strlen(str) + 3);
	if (!res)
		return (NULL);
	while (str[i] && (str[i] != '='))
		res[i++] = str[j++];
	if (str[i] == '=')
	{
		res[j++] = str[i++];
		res[j++] = '"';
	}
	while (str[i])
		res[j++] = str[i++];
	if (str[i] == '\0')
		res[j++] = '"';
	res[j] = '\0';
	return (res);
}
