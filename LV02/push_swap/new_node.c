/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawagu <takawagu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 16:48:41 by takawagu          #+#    #+#             */
/*   Updated: 2025/06/18 16:49:38 by takawagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node)); // ノードのメモリ確保
	if (!node)
		return (NULL);   // malloc失敗時
	node->value = value; // 値を格納
	node->index = -1;    // インデックスは後で設定
	node->next = NULL;   // 最後のノードなので next = NULL
	return (node);       // 作ったノードを返す
}
