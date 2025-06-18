/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:12:01 by takawagu          #+#    #+#             */
/*   Updated: 2025/06/18 16:12:44 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void index_stack(t_node *head)
{
	t_node *cur1 = head;
	t_node *cur2;
	int index;

	while (cur1)
	{
		index = 0;
		cur2 = head;
		while (cur2)
		{
			if (cur2->value < cur1->value)
				index++;
			cur2 = cur2->next;
		}
		cur1->index = index;
		cur1 = cur1->next;
	}
}
