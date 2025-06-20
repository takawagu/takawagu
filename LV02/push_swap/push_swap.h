/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:55:55 by takawagu          #+#    #+#             */
/*   Updated: 2025/06/20 14:23:14 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include<stdlib.h>
#include<unistd.h>

typedef struct s_node {
	int             value;
	int             index;
	struct s_node   *next;
} t_node;

typedef struct s_stack {
	t_node *a;
	t_node *b;
	int     size_a;
	int     size_b;
} t_stack;


void	sa(t_stack *s);
void	sb(t_stack *s);
void	ss(t_stack *s);

void	pa(t_stack *s);
void	pb(t_stack *s);

void	ra(t_stack *s);
void	rb(t_stack *s);
void	rr(t_stack *s);

void	rra(t_stack *s);
void	rrb(t_stack *s);
void	rrr(t_stack *s);


#endif