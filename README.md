# 0x19. C - Stacks, Queues - LIFO, FIFO

## Monty

Monty 0.98 is a scripting language that is first compiled into Monty byte codes
(Just like Python). It relies on a unique stack, with specific instructions to
manipulate it. The goal of this project is to create an interpreter for Monty
ByteCodes files.

### Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the
industry uses this standard but it is not required by the specification of the
language. There is not more than one instruction per line.
There can be any number of spaces before or after the opcode and its argument.
Monty byte code files can contain blank lines (empty or made of spaces only)
and any additional text after the opcode or its required argument is not taken
into account.

## Usage

The program can be compiled by running the [make](https://www.gnu.org/software/make/)
command at the top level of the repository.

```bash
make
```

This will produce a binary file named `monty`. The program takes a path to a
monty bytecode script as an argument, nothing more, nothing less.

```bash
./monty /path/to/monty/bytecodes.m
```

The program will then parse the script line by line and execute any valid
opcodes it finds. If the program encouters an error it will print a message to
[stderr](https://en.wikipedia.org/wiki/Standard_streams#Standard_error_(stderr))
and exit.

## Opcodes

| Opcode | Description |
| :--: | :-- |
| **push \<int>** | Push an integer onto the stack. The argument `<int>` is ***required*** and ***must be an integer***. |
| **pall** | Print all the values on the stack, starting from the top of the stack. |
| **pint** | Print the value at the top of the stack, followed by a new line. The stack ***must not be empty***. |
| **pop** | Remove the top element of the stack. The stack ***must not be empty***. |
| **swap** | Swap the top two elements of the stack. The stack must have ***atleast 2*** elements. |
| **add** | Pop the top two elements of the stack and add them pushing the result back onto the stack. The stack must have ***atleast 2*** elements. |
| **nop** | This opcode is ignored. |
| **sub** | Pop the top two elements of the stack and subtract the top element from the second, then push the result back onto the stack. The stack must have ***atleast 2*** elements. |
| **div** | Pop the top two elements of the stack and divide the second element by the top, then push the result back onto the stack. The stack must have ***atleast 2*** elements. |
| **mul** | Pop the top two elements of the stack and multiply the second element with the top, then push the result back onto the stack. The stack must have ***atleast 2*** elements. |
| **div** | Pop the top two elements of the stack and compute the modulo of the second element by the top, then push the result back onto the stack. The stack must have ***atleast 2*** elements. |
| **#** | This acts a line comment when it ***appears as the first*** non-space character on a line. |
| **pchar** | Print the char at the top of the stack, followed by a new line. The element at the top of the stack ***must be an [ascii](https://en.wikipedia.org/wiki/ASCII)*** character and the stack ***must not be empty***. |
| **pstr** | Print the string formed by the characters in the stack followed by a new line. The opcode will stop printing characters when; it encounters a non-ascii character or a NUL (`\0`) character or it reaches the bottom of the stack. |
| **rotl** | Move the top element of the stack to the bottom. |
| **rotr** | Move the bottom element of the stack to the top. |
| **stack** | Change the data format into a stack (default). |
| **queue** | Change the data format into a queue. The top of the stack becomes the first element of the queue while the bottom of the stack becomes the last element of the queue. |
