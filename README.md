# get_next_line

> The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor.

## Installation

This project requires [GNU Compiler Collection](https://gcc.gnu.org/) v7.5+

```bash
$ git clone https://github.com/caio-vinicius/get_next_line
```

```bash
$ cd get_next_line
```

That's it!

## Usage

You need compile the project

```bash
$ gcc -D BUFFER_SIZE=32 *.c -o gnl
```

And run:

```bash
$ ./gnl
```

You can change the file that will be read on the `main.c` file. On `tests/` folder there are a plenty of files for tests, you can use them. Default file is `alphabet`.

```c
23 fd = open("tests/alphabet", O_RDONLY);
```
