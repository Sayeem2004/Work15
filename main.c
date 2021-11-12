#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char **parse_args(char *line) {
    // Figuring Out Argument Count
    char *copy = strdup(line), *token;
    int cnt = 1;
    while (token = strsep(&line, " ")) {
        cnt++;
    }

    // Creating Argument Array
    char **A = calloc(cnt, sizeof(char *));
    int i = 0;
    while (token = strsep(&copy, " ")) {
        A[i] = token; i++;
    }

    // Returning Argument Array
    return A;
}

int main() {
    // Example Command
    char cmd[] = "ls -a -l";

    // Parsing Command
    char **args = parse_args(cmd);

    // Running Command
    execvp(args[0], args);

    // Ending Function
    return 0;
}
