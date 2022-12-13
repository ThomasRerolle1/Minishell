#include "../I/ft_minishell.h"


#include <readline/history.h>
#include <readline/readline.h>

#include <stdio.h>
#include <stdlib.h>

t_list	*create_list_env(char **envp)
{
	t_list	*list_env;
	t_list	*new_elem;
	int	i;

	i = 0;
	list_env = NULL;
	while (envp[i])
	{
		new_elem = ft_lstnew((void *)envp[i]);
		ft_lstadd_back(&list_env, new_elem);
		i++;
	}
	new_elem->next = NULL;
	return (list_env);
}
	

void	ms_env(char **envp)
{
	t_list	*list_env;

	if (!envp)
	{
		printf("coucou");
		perror(NULL);
	}
	printf("coucou");
	list_env = create_list_env(envp);
	while (list_env->next)
	{
		printf("%s\n", (char *)list_env->content);
		list_env = list_env->next;
	}
	return ;
}

