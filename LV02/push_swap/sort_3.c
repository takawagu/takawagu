/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:36:46 by takawagu          #+#    #+#             */
/*   Updated: 2025/06/18 16:37:25 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void sort_3(t_stack *s)
{
	int a = s->a->index;
	int b = s->a->next->index;
	int c = s->a->next->next->index;

	if (a < b && b < c)
		return ; // すでにソート済み
	else if (a > b && b < c && a < c)
		sa(s); // 2 1 3
	else if (a > b && b > c)
	{
		sa(s); // 3 2 1
		rra(s);
	}
	else if (a > b && b < c && a > c)
		ra(s); // 3 1 2
	else if (a < b && b > c && a < c)
	{
		sa(s); // 1 3 2
		ra(s);
	}
	else if (a < b && b > c && a > c)
		rra(s); // 2 3 1
}