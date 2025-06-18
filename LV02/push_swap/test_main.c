#include "push_swap.h"
#include <stdio.h> // printf

// ノードを作成する関数
t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

// スタックを出力する関数
void	print_stack(const char *name, t_node *stack)
{
	printf("%s: ", name);
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	s;

	// スタックa: 3 → 2 → 1
	s.a = new_node(3);
	s.a->next = new_node(2);
	s.a->next->next = new_node(1);
	// スタックb: 6 → 5 → 4
	s.b = new_node(6);
	s.b->next = new_node(5);
	s.b->next->next = new_node(4);
	s.size_a = 3;
	s.size_b = 3;
	// === Before ===
	printf("Before operations:\n");
	print_stack("a", s.a);
	print_stack("b", s.b);
	// === Test sa ===
	sa(&s);
	print_stack("After sa → a", s.a);
	print_stack("b", s.b);
	// === Test sb ===
	sb(&s);
	print_stack("a", s.a);
	print_stack("After sb → b", s.b);
	// === Test ss ===
	ss(&s);
	print_stack("After ss → a", s.a);
	print_stack("After ss → b", s.b);
	return (0);
}
