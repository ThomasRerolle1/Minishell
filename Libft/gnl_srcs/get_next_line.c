/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:53:59 by mathis            #+#    #+#             */
/*   Updated: 2022/10/08 13:58:48 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_get_line(char *frigo)
{
	int		i;
	char	*res;

	i = 0;
	if (!frigo[i])
		return (NULL);
	while (frigo[i] && frigo[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (frigo[i] && frigo[i] != '\n')
	{
		res[i] = frigo[i];
		i++;
	}
	if (frigo[i] == '\n')
	{
		res[i] = frigo[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_save(char *frigo)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (frigo[i] && frigo[i] != '\n')
		i++;
	if (!frigo[i])
	{
		free(frigo);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (gnl_strlen(frigo) - i + 1));
	if (!res)
		return (NULL);
	i++;
	while (frigo[i])
		res[j++] = frigo[i++];
	res[j] = '\0';
	free(frigo);
	return (res);
}

char	*ft_read_and_save(int fd, char *frigo)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (!gnl_strchr(frigo, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		frigo = gnl_strjoin(frigo, buff);
	}
	free(buff);
	return (frigo);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*frigo;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	frigo = ft_read_and_save(fd, frigo);
	if (!frigo)
		return (NULL);
	res = ft_get_line(frigo);
	frigo = ft_save(frigo);
	return (res);
}
/*
#include <fcntl.h>

int	main(void)
{
	int		fd1;

	fd1 = open("42_with_nl", O_RDONLY);
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));
	printf("<<%s", get_next_line(fd1));

	return (1);
}
*/