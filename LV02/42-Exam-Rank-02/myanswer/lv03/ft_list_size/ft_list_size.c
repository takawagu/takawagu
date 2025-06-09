#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list != NULL)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

t_list	*ft_new_node(void *data)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	return (node);
}

int	main(void)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;
	t_list	*fourth;
	t_list	*solo;
	int		value;

	first = ft_new_node("One");
	second = ft_new_node("Two");
	// safer way for number
	value = 3;
	third = ft_new_node(&value);
	fourth = ft_new_node("Four");
	solo = ft_new_node("Solo");
	first->next = second;
	second->next = third;
	third->next = fourth;
	printf("%d\n", ft_list_size(first));  // 4
	printf("%d\n", ft_list_size(second)); // 3
	printf("%d\n", ft_list_size(third));  // 2
	printf("%d\n", ft_list_size(solo));   // 1
	printf("%d\n", ft_list_size(NULL));   // 0
	printf("%d\n", ft_list_size(fourth)); // 1
	return (0);
}
