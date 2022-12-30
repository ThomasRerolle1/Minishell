#include "../I/ft_minishell.h"

t_token	*create_token(void)
{
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		perror("malloc error: token creation failed");
	new->content = NULL;
	new->raw_content = NULL;
	new->type_of_content = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	fill_token(t_token *token, char *substr)
{
	token->raw_content = substr;
	token->type_of_content = is_separator(substr[0]);
	return ;
}

t_token	*token_last(t_token *first_token)
{
	t_token	*tmp;

	tmp = first_token;
	if (first_token == NULL)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	token_add_back(t_token **first_token, t_token *new_token)
{
	t_token	*last_token;
	if (first_token && *first_token && new_token)
	{
		last_token = token_last(*first_token);
		last_token->next = new_token;
		new_token->prev = last_token;
	}
	if (!(*first_token))
		*first_token = new_token;
}

void	create_fill_add_token(t_token **first_token_in_list, char *raw_content)
{
	t_token	*new_token;

	new_token = create_token();
	fill_token(new_token, raw_content);
	token_add_back(first_token_in_list, new_token);
}

t_token	*make_token_list(char *line)
{
	char	*substr;
	t_token	**token_list;

	token_list = (t_token **)malloc(sizeof(t_token *));
	*token_list = NULL;
	while (*line)
	{
		substr = ft_get_substr(line);
		create_fill_add_token(token_list, substr);
		line = ms_truncate_line(line, substr);
	}
	return (*token_list);
}

/*
int	main()
{
	char	*line = malloc(4024);
	line = "blabla blabla\0";
	char	*substr;
	t_token	**token_list;

	token_list = (t_token **)malloc(sizeof(t_token *));
	*token_list = NULL;
	while (*line)
	{
		substr = ft_get_substr(line);
		create_fill_add_token(token_list, substr);
		line = ms_truncate_line(line, substr);
	}
	t_token	*tmp = *token_list;
	while (tmp)
	{
		printf("content %s type %i\n", tmp->raw_content, tmp->type_of_content);
		tmp = tmp->next;
	}
	return (0);
}
*/
