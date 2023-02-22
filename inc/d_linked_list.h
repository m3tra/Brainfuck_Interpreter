#ifndef D_LINKED_LIST_H
# define D_LINKED_LIST_H

# include <unistd.h>
# include <stdlib.h>

# define DEFAULT_VALUE 0

typedef struct s_cell t_cell;

typedef struct s_cell {
	t_cell*	prev;
	t_cell*	next;
	char	value;
}	t_cell;

extern t_cell*	curr;

t_cell*	new_node(t_cell* prev);
void	free_nodes(t_cell* node);

#endif
