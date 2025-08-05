/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 09:19:11 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:29:30 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int	main(void)
// {
// 	char *str = strdup("Hello");
// 	t_list *node = ft_lstnew(str);

// 	if (node && node->content)
// 		printf("Node content: %s\n", (char *)node->content);
// 	else
// 		printf("Node creation failed.\n");

// 	free(node->content);
// 	free(node);
// 	return (0);
// }