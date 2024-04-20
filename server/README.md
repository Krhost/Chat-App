# Server

This project consists of a server application. This application can be compiled and executed using a Makefile provided in the project's main directory.

## Compilation and Execution

To compile and execute the project, follow these steps :

### Compilation

To compile the project, run the following command in the project's root directory :
```bash
make
```
This will compile the source files (`.c`) located in the `src/` directory and create object files (`.o`) in the `build/` directory. Then, the executable (`mysh`) is generated in the `bin/` directory.

### Execution

To execute the compiled program, use the following command:
```bash
make exec
```
This will execute the executable file (`mysh`) located in the `bin/` directory.

### Execution with Valgrind

To execute the program with Valgrind, use the following command :
```bash
make valgrind
```
This will execute the program using Valgrind to detect memory leaks and other memory management issues.

### Cleaning

To clean up the object files and executable, you can use the following commands :

* Clean up object files and executable :
```bash
make clean
```
This command will remove all object files (`.o`) in the `build/` directory and the executable in the `bin/` directory.

* Full cleanup :
```bash
make fullclean
```
This command will remove the entire `build/` and `bin/` directories, including all object files and the executable.