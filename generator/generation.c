/*
** EPITECH PROJECT, 2023
** dante
** File description:
** perfect
*/

#include "generator.h"

static void break_walls(char *maze, int x, int y)
{
    int num_openings = (x * y) / 10;

    for (int i = 0; i < num_openings; i++) {
        int x_pos = rand() % x;
        int y_pos = rand() % y;
        maze[y_pos * x + x_pos] = '*';
    }
}

static void init_maze(char *maze, int x, int y)
{
    for (int i = 0; i < x * y; i += 1) {
        if (i % x == 0 || i < x)
            maze[i] = '*';
        else
            maze[i] = 'X';
    }
    maze[x * y] = '\0';
    maze[0] = '*';
    maze[(y - 1) * x + x - 1] = '*';
    if (x % 2 == 0)
        maze[(y - 1) * x + x - 2] = '*';
    if (y % 2 == 0) {
        maze[(y - 1) * x + x - 2] = '*';
        maze[(y - 2) * x + x - 2] = '*';
    }
}

char *maze_generation(int x, int y, status_t status)
{
    char *maze = malloc(sizeof(char) * (x * y + 1));

    init_maze(maze, x, y);
    if (status == IMPERFECT)
        break_walls(maze, x, y);
    for (int i = 2; i < y; i += 2) {
        for (int j = 2; j < x; j += 2) {
            maze[i * x + j] = '*';
            (rand() % 2 == 1)
            ? (maze[(i - 1) * x + j] = '*')
            : (maze[i * x + j - 1] = '*');
        }
    }
    return (maze);
}
