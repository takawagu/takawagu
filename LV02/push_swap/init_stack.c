/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:40:41 by takawagu          #+#    #+#             */
/*   Updated: 2025/06/18 16:47:31 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void append_node(t_node **stack, t_node *new)
{
	t_node *temp;

	if (!*stack)
	{
		*stack = new;  // スタックが空なら new が先頭になる
		return;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;  // 最後までたどる
	temp->next = new;      // 最後の next に new をつなぐ
}


int	init_stack(t_stack *stack, int argc, char **argv)
{
	int		i;
	int		value;
	t_node	*node;

	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	i = 1; // argv[0] はプログラム名
	while (i < argc)
	{
		value = ft_atoi(argv[i]); // 整数に変換（要エラーチェック）
		node = new_node(value);
		if (!node)
			return (0); // malloc失敗時
		append_node(&stack->a, node);
		stack->size_a++;
		i++;
	}
	return (1); // 成功
}
