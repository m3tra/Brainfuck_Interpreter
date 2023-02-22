#ifndef COMMANDS_H
# define COMMANDS_H

// Brainfuck commands

void	move_right();	// >
void	move_left();	// <
void	increment();	// +
void	decrement();	// -
void	print_value();	// .
void	read_value();	// ,
int		while_loop(const char* code);	// []

// Extra

void	print_debug();	// #

#endif
