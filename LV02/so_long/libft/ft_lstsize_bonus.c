/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:50:55 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:58:47 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int	main(void)
// {
// 	t_list *n1 = ft_lstnew("A");
// 	t_list *n2 = ft_lstnew("B");
// 	t_list *n3 = ft_lstnew("C");

// 	ft_lstadd_front(&n2, n1);
// 	ft_lstadd_back(&n1, n3);

// 	printf("ノード数: %d\n", ft_lstsize(n1));

// 	ft_lstclear(&n1, free);
// 	return (0);
// }