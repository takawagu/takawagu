/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:04:32 by takawagu          #+#    #+#             */
/*   Updated: 2025/06/20 14:51:46 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
#include <unistd.h>

static 	reverse_rotate(t_node **head)
{
	t_node	*prev;
	t_node	*last;

	if (!*head || !(*head)->next)
		return ;
	prev = NULL;
	last = *head;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *head;
	*head = last;
}

void	rra(t_stack *stack)
{
	reverse_rotate(&stack->a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack)
{
	reverse_rotate(&stack->b);
	write(1, "rrb\n", 4);
}