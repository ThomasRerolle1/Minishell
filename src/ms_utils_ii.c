/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils_II.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 16:07:34 by mravera           #+#    #+#             */
/*   Updated: 2022/12/16 16:10:38 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

char	*ms_new_pwd(char *old_pwd)
{
	char	*buff;
	char	*new_pwd;

	buff = getcwd(NULL, 0);
	free(old_pwd);
	new_pwd = ft_strjoin("PWD=", buff);
	free(buff);
	return (new_pwd);
}
