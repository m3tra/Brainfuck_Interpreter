#include "brainfuck.h"

// Moves current cell's pointer to next cell (to the right)
void	move_right() {
	if (!curr->next)
		curr->next = new_node(curr);
	curr = curr->next;
	++pos;
}

// Moves current cell's pointer to previous cell (to the left) if it exists
void	move_left() {
	if (!curr->prev)
		return;
	curr = curr->prev;
	--pos;
}

// Increments current cell's value by 1
void	increment() {
	++(curr->value);
}

// Decrements current cell's value by 1
void	decrement() {
	if (curr->value)
		--(curr->value);
}

// Prints character to output file
void	print_value() {
	fputc(curr->value, conf.out_file);
}

// Reads character from input file
void	read_value() {
	int	c;

	if (conf.input)
		curr->value = *(conf.input++);
	else if ((c = fgetc(conf.in_file)) != EOF)
		curr->value = c == '\n' ? 10 : c;
}

// Recursively interprets while loops
int		while_loop(const char* code) {
	size_t	i = 0;
	size_t	bracket_pairs = 1;
	char*	inner_code = calloc(strlen(code), sizeof(char));
	if (!inner_code)
		perr("Failed inner_code calloc");

	/**
	 *	Loop through each following char until current loop's
	 *	closing bracket is found and save it to inner_code string
	 *	Then recursively interpret the inner_code
	**/
	while (*code) {
		if (*code == '[')
			++bracket_pairs;
		else if (*code == ']')
			--bracket_pairs;

		*(inner_code + i++) = *code++;

		if (!bracket_pairs)
			break;
	}

	// Leave loop once current cell has value of 0
	while (curr->value)
		interpret(inner_code);

	free(inner_code);
	return i;
}

// Prints current cell position and value
void	print_debug() {
	printf("cell #%ld: %d\n", pos, curr->value);
}
