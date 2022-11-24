/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <@student.42lausanne.ch>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:10:13 by mravera           #+#    #+#             */
/*   Updated: 2021/12/16 16:39:57 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tmp;

	if (!lst)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (!head)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, tmp);
	}
	return (head);
}
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_lst;
	t_list *elem;

	if (!lst)
		return (0);
	new_lst = 0;
	while (lst)
	{
		if (!(elem = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, elem);
		lst = lst->next;
	}
	return (new_lst);
}
*/

/*
void	*lstmap_f(void *content)
{
	(void)content;
	return("OK !");
}
*/

/*
int	main(void)
{
	printf("oioioii");
	t_list *l = ft_lstnew(ft_strdup(" 1 2 3 "));
	t_list *ret;

	printf("1111111");
	l->next = ft_lstnew(ft_strdup("ss"));
	l->next->next = ft_lstnew(ft_strdup("-_-"));
	printf("222222");

	ret = ft_lstmap(l, lstmap_f, ((void *)0));

	printf("res1 = %s\n", ret->content);
	printf("res2 = %s\n", ret->next->content);
	printf("res3 = %s\n", ret->next->next->content);
}
*/
