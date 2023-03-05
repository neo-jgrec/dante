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
    generator.maze.size = (vector2i_t){atoi(av[1]), atoi(av[2])};
    if (generator.maze.size.x <= 1 || generator.maze.size.y <= 1)
        return 84;
    if (ac == 4 && strcmp(av[3], "perfect") == 0)
        generator.status = PERFECT;
    else if (ac == 3 || (ac == 4 && strcmp(av[3], "imperfect") == 0))
        generator.status = IMPERFECT;
    else
        return 84;
    generator.seed = time(NULL);
    srand(generator.seed);
    generator.maze.map = maze_generation(generator.maze.size.x,
    generator.maze.size.y, generator.status);
    print_maze(generator.maze.map, generator.maze.size.x,
    generator.maze.size.y);
    return 0;
}
