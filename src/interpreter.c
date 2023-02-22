#include "brainfuck.h"

// Checks for unpaired '[' or ']'
void	check_for_missing_bracket(const char *code) {
	if (!code)
		perr("Missing code in function check_for_missing_bracket");

	size_t	unpaired;
	for (unpaired = 0; *code; code++) {
		if (*code == '[')
			++unpaired;
		else if (*code == ']') {
			if (unpaired < 1)
				perr("Unmatched ]");
			--unpaired;
		}
	}
	if (unpaired > 0)
		perr("Unmatched [");
}

void	interpret(const char* code) {
	if (!code)
		perr("Missing code in function interpret");

	while (*code) {
		switch (*code++) {
			case '>':
				move_right(); break;
			case '<':
				move_left(); break;
			case '+':
				increment(); break;
			case '-':
				decrement(); break;
			case '.':
				print_value(); break;
			case ',':
				read_value(); break;
			case '[':
				code += while_loop(code); break;
			case ']':
				break;
			case '#':
				print_debug(); break;
		}
	}
}
