/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:24:54 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:28:59 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	char	*str;
// 	t_list	*node;

// 	str = malloc(6);
// 	if (!str)
// 		return (1);
// 	str[0] = 'H';
// 	str[1] = 'e';
// 	str[2] = 'l';
// 	str[3] = 'l';
// 	str[4] = 'o';
// 	str[5] = '\0';
// 	node = ft_lstnew(str);
// 	printf("Before delete: %s\n", (char *)node->content);
// 	ft_lstdelone(node, del);
// 	printf("Node deleted successfully.\n");
// 	return (0);
// }
