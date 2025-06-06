/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:50:17 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:29:10 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// void	*dup_uppercase(void *s)
// {
// 	char	*str;
// 	char	*res;

// 	str = (char *)s;
// 	res = strdup(str);
// 	for (int i = 0; res[i]; i++)
// 		res[i] = toupper(res[i]);
// 	return (res);
// }

// void	free_str(void *s)
// {
// 	free(s);
// }

// int	main(void)
// {
// 	t_list	*l1;
// 	t_list	*l2;
// 	t_list	*upper;

// 	l1 = ft_lstnew(strdup("hello"));
// 	l2 = ft_lstnew(strdup("libft"));
// 	ft_lstadd_back(&l1, l2);
// 	upper = ft_lstmap(l1, dup_uppercase, free_str);
// 	printf("%s\n", (char *)upper->content);       // HELLO
// 	printf("%s\n", (char *)upper->next->content); // LIBFT
// 	ft_lstclear(&l1, free_str);
// 	ft_lstclear(&upper, free_str);
// 	return (0);
// }
