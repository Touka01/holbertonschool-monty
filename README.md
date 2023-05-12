# Monty

Monty is an interpreter for Monty Bytecode files. It reads Monty Bytecode files, which contain instructions for manipulating a stack, and executes the instructions accordingly.

## Usage

To run the Monty interpreter, use the following command:

./monty file

Where `file` is the path to the Monty Bytecode file you want to execute.

## Features

Monty supports the following operations:

- `push`: Pushes an element onto the stack.
- `pall`: Prints all the elements in the stack.
- `pint`: Prints the value at the top of the stack.
- `pop`: Removes the top element from the stack.
- `swap`: Swaps the top two elements of the stack.
- `add`: Adds the top two elements of the stack.
- `nop`: Does nothing.

## Monty Bytecode File Format

Monty Bytecode files contain one instruction per line. Each instruction consists of an opcode followed by an optional argument. Opcodes and arguments are separated by spaces or tabs.

Example Monty Bytecode file:
push 1
push 2
push 3
pall

This file pushes the values 1, 2, and 3 onto the stack, and then prints all the elements in the stack.

## Error Handling

If an error occurs during the execution of the Monty interpreter, an error message will be printed to stderr, and the interpreter will exit with a status of EXIT_FAILURE.

## Coding Style

The Monty codebase follows the Betty coding style, which is a set of guidelines for writing C code. The code is properly indented and formatted for readability.

## Building the Monty Interpreter

To build the Monty interpreter, use the following command:

gcc -Wall -Werror -Wextra -pedantic *.c -o monty

This command compiles all the source code files and generates an executable file named `monty`.

## Author

Ahmed Toukebri

