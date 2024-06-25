#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_STACK_SIZE 100
#define PATH_MAX 4096

typedef struct {
    char directories[MAX_STACK_SIZE][PATH_MAX];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_STACK_SIZE - 1;
}

void push(Stack *s, const char *dir) {
    if (isFull(s)) {
        const char *msg = "Stack overflow\n";
        write(2, msg, strlen(msg));
        _exit(1);
    }
    strncpy(s->directories[++s->top], dir, PATH_MAX);
}

void pop(Stack *s, char *dir) {
    if (isEmpty(s)) {
        const char *msg = "Stack underflow\n";
        write(2, msg, strlen(msg));
        _exit(1);
    }
    strncpy(dir, s->directories[s->top--], PATH_MAX);
}

void my_getcwd(char *buffer, size_t size) {
    if (getcwd(buffer, size) == NULL) {
        const char *msg = "getcwd() error\n";
        write(2, msg, strlen(msg));
        _exit(1);
    }
}

void my_chdir(const char *path) {
    if (chdir(path) != 0) {
        const char *msg = "chdir() error\n";
        write(2, msg, strlen(msg));
        _exit(1);
    }
}

void writeStr(int fd, const char *str) {
    write(fd, str, strlen(str));
}

void handlePushd(Stack *stack, const char *newDir) {
    char currentDir[PATH_MAX];
    my_getcwd(currentDir, sizeof(currentDir));

    push(stack, currentDir);
    my_chdir(newDir);

    writeStr(1, "Changed directory to ");
    writeStr(1, newDir);
    writeStr(1, "\n");
}

void handlePopd(Stack *stack) {
    if (isEmpty(stack)) {
        const char *msg = "No directories in stack\n";
        write(2, msg, strlen(msg));
        return;
    }

    char dir[PATH_MAX];
    pop(stack, dir);
    my_chdir(dir);

    writeStr(1, "Changed directory to ");
    writeStr(1, dir);
    writeStr(1, "\n");
}

int main(int argc, char *argv[]) {
    static Stack dirStack;
    initStack(&dirStack);

    if (argc < 2) {
        const char *msg = "Usage: <command> [directory]\n";
        write(2, msg, strlen(msg));
        _exit(1);
    }

    const char *command = argv[1];

    if (strcmp(command, "pushd") == 0) {
        if (argc != 3) {
            const char *msg = "Usage: pushd <directory>\n";
            write(2, msg, strlen(msg));
            _exit(1);
        }
        handlePushd(&dirStack, argv[2]);
    } else if (strcmp(command, "popd") == 0) {
        handlePopd(&dirStack);
    } else {
        const char *msg = "Unknown command\n";
        write(2, msg, strlen(msg));
        _exit(1);
    }

    return 0;
}
