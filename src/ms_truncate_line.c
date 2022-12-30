#include "../I/ft_minishell.h"

char	*ms_truncate_line(char *line, char *substr)
{
	char	*new_line;
	int		start;
	int		end;
	
	start = ft_strlen(substr);
	end = ft_strlen(line);
	new_line = ft_substr(line, start, end);
	//free(line);
	line = NULL;
	return (new_line);
}

/*
int	main()
{
	char	*line = "";
	char	*substr = "123";
	char	*new_line = ms_truncate_line(line, substr);
	printf("line %s\nsub  %s\nnew  %s\n", line, substr, new_line);
	while (*new_line)
		new_line++;
	return (0);
}
*/
