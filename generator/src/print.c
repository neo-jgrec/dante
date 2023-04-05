/*
** EPITECH PROJECT, 2023
** my_dante
** File description:
** print
*/

#include <unistd.h>

void print_maze(char *maze, int x, int y)
{
    for (int h = 0; h < y - 1; h += 1) {
        write(1, maze + h * x, x);
        write(1, "\n", 1);
    }
    write(1, maze + (y - 1) * x, x);
}
