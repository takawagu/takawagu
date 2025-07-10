/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:37:04 by takawagu          #+#    #+#             */
/*   Updated: 2025/06/20 14:59:25 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_stack *stack)
{
	if (is_sorted(stack->a))
		return ;
	if (stack->size_a == 2)
		sa(stack);
	else if (stack->size_a == 3)
		sort_3(stack);
	else if (stack->size_a <= 5)
		sort_5(stack);
	else
		sort_big(stack); // チャンク等で500個対応
}
