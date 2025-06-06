/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:39:19 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:59:31 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

// int	main(void)
// {
// 	t_list *head = NULL;
// 	t_list *new1 = ft_lstnew(strdup("World"));
// 	t_list *new2 = ft_lstnew(strdup("Hello"));

// 	ft_lstadd_front(&head, new1);
// 	ft_lstadd_front(&head, new2);

// 	t_list *curr = head;
// 	while (curr)
// 	{
// 		printf("%s\n", (char *)curr->content);
// 		curr = curr->next;
// 	}
// 	// free omitted for brevity
// 	return (0);
// }