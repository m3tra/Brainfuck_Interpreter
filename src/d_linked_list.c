#include "d_linked_list.h"

t_cell*	new_node(t_cell* prev) {
	t_cell*	node = malloc(sizeof(t_cell));

	node->prev = prev;
	node->next = NULL;
	node->value = DEFAULT_VALUE;

	return node;
}

void	free_nodes(t_cell* cell) {
	if (!cell)
		return;

	t_cell*	tmp;
	// Free left side of current node
	while (cell->prev) {
		tmp = cell->prev;
		cell->prev = cell->prev->prev;
		free(tmp);
	}
	// Free right side of current node
	while (cell->next) {
		tmp = cell->next;
		cell->next = cell->next->next;
		free(tmp);
	}
	free(cell);
}
