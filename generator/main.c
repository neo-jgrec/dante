/*
** EPITECH PROJECT, 2023
** dante
** File description:
** main
*/

#include "generator.h"

void perfect_maze(generator_t *generator);
void imperfect_maze(generator_t *generator);

void init_maze(generator_t *generator)
{
    generator->maze.map = malloc(sizeof(int *) * generator->maze.height);
    for (int i = 0; i < generator->maze.height; i++) {
        generator->maze.map[i] = malloc(sizeof(int) * generator->maze.width);
        for (int j = 0; j < generator->maze.width; j++)
            generator->maze.map[i][j] = 0;
    }
}

int main(int ac, char **av)
{
    generator_t generator;

    if (ac < 3)
        return 84;

    generator.maze.width = atoi(av[1]);
    generator.maze.height = atoi(av[2]);

    if (generator.maze.width <= 0 || generator.maze.height <= 0)
        return 84;

    if (ac == 4 && strcmp(av[3], "perfect") == 0)
        generator.status = PERFECT;
    else
        generator.status = IMPERFECT;

    init_maze(&generator);
    generator.seed = time(NULL);

    if (generator.status == PERFECT)
        perfect_maze(&generator);
    else
        imperfect_maze(&generator);

    for (int i = 0; i < generator.maze.height; i++) {
        for (int j = 0; j < generator.maze.width; j++)
            printf("%d", generator.maze.map[i][j]);
        printf("\n");
    }

    return 0;
}

void perfect_maze(generator_t *generator)
{
}


void imperfect_maze(generator_t *generator)
{
}
