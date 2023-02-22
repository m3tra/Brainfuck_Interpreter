#include "brainfuck.h"

// Prints custom error message and exits the program
void	perr(const char *error) {
	if (!error)
		perr("Missing error in function perr");

	printf(RED"Error: "WHITE);
	printf("%s\n", error);
	exit(EXIT_FAILURE);
}

// Closes any open file stream and frees malloc'd memory
void	cleanup(const char *code) {
	if (!code)
		perr("Missing code in function cleanup");

	fclose(conf.in_file);
	fclose(conf.out_file);

	free((void*)code);
	free_nodes(curr);
}

// Ingests from specified brainfuck code input file
// Returns code as string
const char*	read_file() {
	char	buffer[BUFFER_SIZE];
	size_t	i = 0;

	char*	code = malloc(sizeof(char) * BUFFER_SIZE);
	if (!code)
		perr("Error initializing code buffer");

	while (fgets(buffer, BUFFER_SIZE, conf.in_file)) {
		memcpy(code + i, buffer, BUFFER_SIZE);
		i += strlen(buffer);
		code = realloc(code, i + BUFFER_SIZE);
	}
	return code;
}
