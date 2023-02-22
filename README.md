# Brainfuck_Interpreter

 This program interprets brainfuck code read from a file or argument via C

 A double linked list is used as the array of memory cells to allow a dynamic storage capacity instead of a fixed-size one

 A few tests from <http://brainfuck.org/tests.b> are included

 Usage: ./brainterpreter -f | -o | -i
    -i | --input file     read from file
    -o | --output file    output to file
    -c | --code code      code as argument
