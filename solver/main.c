/*
** EPITECH PROJECT, 2023
** Solver
** File description:
** Program entry point
*/

#include <stdio.h>
#include "solver.h"

int main(int argc, char **argv)
{
    if (!argc || argc > 2 || !argv || !*argv || !**argv
        || (argc == 2 && (!argv[1] || !*(argv[1]))))
        return 84;
    FILE *stream = stdin;
    if (!(argc == 1 || (*(argv[1]) == '-' && !argv[1][1]))
        && !(stream = fopen(argv[1], "r"))) {
        perror(*argv);
        return 84;
    }
    int ret = solve(stream);
    if (stream != stdin)
        fclose(stream);
    return ret;
}
