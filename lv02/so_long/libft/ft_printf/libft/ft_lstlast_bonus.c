/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 10:00:12 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:56:45 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list *a = ft_lstnew(strdup("First"));
// 	t_list *b = ft_lstnew(strdup("Second"));
// 	a->next = b;

// 	t_list *last = ft_lstlast(a);
// 	printf("Last content: %s\n", (char *)last->content);

// 	return (0);
// }