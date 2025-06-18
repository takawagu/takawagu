/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:05:34 by takawagu          #+#    #+#             */
/*   Updated: 2025/06/18 15:29:27 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa sb ss

#include "push_swap.h"
#include <unistd.h>

// スタックaの先頭2ノードをスワップ
void	sa(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s->a || !s->a->next)
		return ;
	first = s->a;
	second = s->a->next;
	first->next = second->next;
	second->next = first;
	s->a = second;
	write(1, "sa\n", 3);
}

// スタックbの先頭2ノードをスワップ
void	sb(t_stack *s)
{
	t_node	*first;
	t_node	*second;

	if (!s->b || !s->b->next)
		return ;
	first = s->b;
	second = s->b->next;
	first->next = second->next;
	second->next = first;
	s->b = second;
	write(1, "sb\n", 3);
}

// aとbを同時にスワップ
void	ss(t_stack *s)
{
	int		flag;
	t_node	*a_first;
	t_node	*a_second;
	t_node	*b_first;
	t_node	*b_second;

	flag = 0;
	if (s->a && s->a->next)
	{
		a_first = s->a;
		a_second = s->a->next;
		a_first->next = a_second->next;
		a_second->next = a_first;
		s->a = a_second;
		flag = 1;
	}
	if (s->b && s->b->next)
	{
		b_first = s->b;
		b_second = s->b->next;
		b_first->next = b_second->next;
		b_second->next = b_first;
		s->b = b_second;
		flag = 1;
	}
	if (flag)
		write(1, "ss\n", 3);
}
