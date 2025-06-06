/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:42:02 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:58:39 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list *a = ft_lstnew(strdup("One"));
// 	t_list *b = ft_lstnew(strdup("Two"));
// 	t_list *c = ft_lstnew(strdup("Three"));
// 	a->next = b;
// 	b->next = c;

// 	ft_lstclear(&a, del);
// 	return (0); // Check with valgrind
// }
