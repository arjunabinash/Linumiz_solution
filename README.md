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

1.1. The stack is used to keep track of directories.
1.2. initStack initializes the stack.
1.3. isEmpty and isFull check the stack status.
1.4. push adds a directory to the stack.
1.5. pop removes and returns the top directory from the stack.

2. Directory Handling:

2.1. my_getcwd and my_chdir wrap the system calls getcwd and chdir, handling errors directly.
2.2. writeStr writes a string to a given file descriptor.

3. Command Handling:

3.1. handlePushd saves the current directory to the stack and changes to the new directory.
3.2. handlePopd restores the previous directory from the stack.
3.3. The main function processes command-line arguments and calls the appropriate handler.
