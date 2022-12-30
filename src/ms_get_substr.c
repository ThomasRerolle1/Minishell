#include "../I/ft_minishell.h"
#include "../Libft/libft.h"

int		is_separator(char c)
{
	if (!c)
		return (0);
	if (c == ' ')
		return (1);
	if (c == '<' || c == '>')
		return (2);
	if (c == 34)
		return (3);
	if (c == 39)
		return (4);
	else
		return (5);
}

char	*ft_substr_word_space(char *line)
{
	char	*substr;
	int		i;

	i = 0;
	while (line[i + 1] && is_separator(line[i + 1]) == is_separator(line[i]))
		i++;
	substr = ft_substr(line, 0, i + 1);
	//printf("index %i\nstrlen %lu\nline %s\nsubstr %s\n", i, strlen(line), line, substr);
	return (substr);
}

char	*ft_substr_quote(char *line)
{
	char	*substr;
	int		i;

	i = 1;
	while (line[i] && line[i] != line[0])
		i++;
	substr = ft_substr(line, 0, i + 1);
	//printf("index %i\nstrlen %lu\nline %s\nsubstr %s\n", i, strlen(line), line, substr);
	return (substr);
}

char	*ft_substr_redirection(char *line)
{
	char	*substr;
	int		i;

	i = 0;
	while (line[i + 1] && line[i] == line[i + 1])
		i++;
	if (i > 1)
	{
		perror("Too much chevrons\n");
		return (NULL);
	}
	substr = ft_substr(line, 0, i + 1);
	//printf("index %i\nstrlen %lu\nline %s\nsubstr %s\n", i, strlen(line), line, substr);
	return (substr);
}

char	*ft_get_substr(char *line)
{
	char	*substr;

	if (is_separator(line[0]) == 0)
		return (NULL);
	if (is_separator(line[0]) == 1)
		substr = ft_substr_word_space(line);
	if (is_separator(line[0]) == 2)
		substr = ft_substr_redirection(line);
	if (is_separator(line[0]) == 3 || is_separator(line[0]) == 4)
		substr = ft_substr_quote(line);
	if (is_separator(line[0]) == 5)
		substr = ft_substr_word_space(line);
	return (substr);
}


/*
int	main()
{
	char *line = "''";

	char *substr = NULL;
	substr = ft_get_substr(line);
	if (substr)
	{
		while (*substr)
			substr++;
	}
	return (0);
}*/
