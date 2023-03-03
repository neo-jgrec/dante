/*
** EPITECH PROJECT, 2023
** dante
** File description:
** main
*/

#include "generator.h"

void print_maze(char *maze, int x, int y)
{
    for (int h = 0; h < y - 1; h += 1) {
        write(1, maze + h * x, x);
        write(1, "\n", 1);
    }
    write(1, maze + (y - 1) * x, x);
}

int main(int ac, char **av)
{
    generator_t generator;

    if (ac < 3)
        return 84;
    generator.maze.width = atoi(av[1]);
    generator.maze.height = atoi(av[2]);
    if (generator.maze.width <= 1 || generator.maze.height <= 1)
        return 84;
    if (ac == 4 && strcmp(av[3], "perfect") == 0)
        generator.status = PERFECT;
    else
        generator.status = IMPERFECT;
    generator.seed = time(NULL);
    srand(generator.seed);
    generator.maze.map = maze_generation(generator.maze.width,
    generator.maze.height, generator.status);
    print_maze(generator.maze.map, generator.maze.width,
    generator.maze.height);
    return 0;
}
