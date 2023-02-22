#include "brainfuck.h"

/*
 *	Inspired by https://github.com/leplastic/brainfuck-interpreter
*/

t_cell*	curr;
size_t	pos = 0;
t_conf	conf = {0};

// Prints help menu to terminal
void	show_help() {
	printf("Usage: ./%s -f | -o | -i\n", PROGRAM_NAME);
	printf("\t[-i|--input <file>]\tread from file\n");
	printf("\t[-o|--output <file>]\toutput to file\n");
	printf("\t[-c|--code <code>]\tcode as argument\n");
	exit(EXIT_FAILURE);
}

void	handle_args(int argc, const char** argv) {
	// (void)argc;
	if (argc == 1)
		show_help();

	while (*++argv) {
		if (!*(argv + 1))
			show_help();

		if (!strcmp("-i", *argv) || !strcmp("--input", *argv)) {
			conf.in_file = fopen(*++argv, "r");
			if (!conf.in_file)
				perr("Could not open input file");
		}
		else if (!strcmp("-c", *argv) || !strcmp("--code", *argv)) {
			conf.input = calloc(strlen(*++argv) + 1, sizeof(char));
			strcpy(conf.input, *argv);
		}
		else if (!strcmp("-o", *argv) || !strcmp("--output", *argv)) {
			conf.out_file = fopen(*++argv, "w");
			if (!conf.out_file)
				perr("Could not open output file");
		}
	}
	if (!conf.in_file) {
		conf.in_file = stdin;
		// if (!conf.input)
		// 	printf("*Interpreting in live mode*\nInput: ");
	}
	if (!conf.out_file)
		conf.out_file = stdout;
}

int		main(int argc, const char** argv) {
	handle_args(argc, argv);

	const char*	code = conf.input ? conf.input : read_file();

	check_for_missing_bracket(code);
	curr = new_node(NULL);

	interpret(code);

	cleanup(code);
	return 0;
}
