/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:53:20 by mravera           #+#    #+#             */
/*   Updated: 2022/12/07 17:36:52 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../I/ft_minishell.h"

int	ms_pwd(char **str)
{
	char	*buffer;
	size_t	siz;
	size_t	max_siz;

	if (ms_strlen_tab(str) != 0)
	{
		printf("pwd: too many arguments\n");
		return (1);
	}
	siz = 50;
	max_siz = 2048;
	buffer = malloc((sizeof(char) * siz) + 1);
	buffer[siz] = '\0';
	while (getcwd(buffer, siz) == NULL && siz <= max_siz)
	{
		siz += 50;
		free(buffer);
		buffer = malloc((sizeof(char) * siz) + 1);
		buffer[siz] = '\0';
	}
	printf("%s\n", buffer);
	free(buffer);
	return (0);
}
