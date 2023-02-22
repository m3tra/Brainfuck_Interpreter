#ifndef BRAINFUCK_H
# define BRAINFUCK_H

# include "d_linked_list.h"
# include "commands.h"
# include "color.h"

# include <stdio.h>
# include <string.h>
# include <stdbool.h>

# define PROGRAM_NAME	"brainterpreter"
# define BUFFER_SIZE	1024

typedef struct s_conf
{
	FILE*	in_file;
	FILE*	out_file;
	char*	input;
	bool	encoding;
}	t_conf;

extern t_conf	conf;
extern size_t	pos;

void		perr(const char *error);
void		cleanup(const char *code);
const char*	read_file();

void		check_for_missing_bracket(const char *code);
void		interpret(const char* code);

#endif


// EOL = 10
