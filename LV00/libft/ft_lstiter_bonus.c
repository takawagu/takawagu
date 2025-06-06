/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:44:51 by takawagu          #+#    #+#             */
/*   Updated: 2025/05/08 16:27:59 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// #include <ctype.h>
// #include <string.h>

// void	to_upper_first_letter(void *content)
// {
// 	char	*str;

// 	str = (char *)content;
// 	if (str && str[0])
// 		str[0] = toupper(str[0]);
// }

// int	main(void)
// {
// 	t_list *n1 = ft_lstnew(strdup("hello"));
// 	t_list *n2 = ft_lstnew(strdup("world"));
// 	t_list *n3 = ft_lstnew(strdup("list"));

// 	n1->next = n2;
// 	n2->next = n3;

// 	ft_lstiter(n1, to_upper_first_letter);

// 	printf("%s\n", (char *)n1->content);
// 	printf("%s\n", (char *)n2->content);
// 	printf("%s\n", (char *)n3->content);

// 	ft_lstclear(&n1, free);
// 	return (0);
// }