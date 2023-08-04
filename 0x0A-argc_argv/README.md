# Argc and Argv

In C programming, `argc` and `argv` are parameters typically used in the `main` function to handle command-line arguments passed to a C program when it is executed from the command line or terminal.

Here's what each of them means:

1. `argc` (argument count): This is an integer variable that represents the number of command-line arguments passed to the program. It includes the name of the program itself as the first argument, so `argc` is always at least 1.

2. `argv` (argument vector): This is an array of strings (character pointers) that holds the actual command-line arguments. Each element of the array (`argv[0]`, `argv[1]`, and so on) is a pointer to a null-terminated string containing one of the arguments. The first element (`argv[0]`) is the name of the program itself.

Here's a simple example of how `argc` and `argv` are used in the `main` function:

```c
#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("Number of arguments: %d\n", argc);

    for (int i = 0; i < argc; i++) {
        printf("Argument %d: %s\n", i, argv[i]);
    }

    return 0;
}
```

If you compile and run this program with the command `./program_name arg1 arg2 arg3`, you would get output similar to:

```
Number of arguments: 4
Argument 0: ./program_name
Argument 1: arg1
Argument 2: arg2
Argument 3: arg3
```

This mechanism allows you to pass information to your C program when you run it from the command line, making your program more versatile and interactive. You can use these command-line arguments for various purposes, such as configuration settings, input file names, output file names, and more.
