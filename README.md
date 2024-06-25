The recruitment process will be,
1. Screening open question to solve in C (under Linux environment)

Screening question:
- Implement pushd and popd Linux commands in C programming.

Conditions:
- Program must be compiled and executed in Linux environment
- Parogram should accept command-line arguments only
- Pre-build Linux applications such as ls, mkdir, etc, and pre-build functions like
system(), popen() should not be used in your application
- Solutions developed in/for Windows machines are not accepted

Solution: 

1. Stack Data Structure:

- The stack is used to keep track of directories.
- initStack initializes the stack.
- isEmpty and isFull check the stack status.
- push adds a directory to the stack.
- pop removes and returns the top directory from the stack.

2. Directory Handling:

- my_getcwd and my_chdir wrap the system calls getcwd and chdir, handling errors directly.
- writeStr writes a string to a given file descriptor.

3. Command Handling:

- handlePushd saves the current directory to the stack and changes to the new directory.
- handlePopd restores the previous directory from the stack.
- The main function processes command-line arguments and calls the appropriate handler.
