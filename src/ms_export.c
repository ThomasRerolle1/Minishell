#include "../I/ft_minishell.h"
#include <string.h>

void	add_new_env_variable(t_list *list_env, char *string_to_parse)
{
	t_list	*new_elem;

	new_elem = ft_lstnew((void *)string_to_parse);
	ft_lstadd_back(&list_env, new_elem);

}

void	ms_export(char**envp, char *string_to_parse)
{
	t_list	*list_env;

	if (!string_to_parse)
		return (ms_env(envp));
	
	list_env = create_list_env(envp);
	add_new_env_variable(list_env, string_to_parse);
}

int	main(int argc, char **argv, char **envp)
{
	if (strcmp(argv[1], "export") == 0)
		ms_export(envp, argv[2]);
	ms_env(envp);
	return (0);

}
