/*
** EPITECH PROJECT, 2023
** dante
** File description:
** main
*/

#include "generator.h"

void printMaze(int *maze, int width, int height) {
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            if (MAZE(x, y) == 0) {
                printf("*");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

void generateMaze(int *maze, int width, int height, int x, int y)
{
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dirOrder[4] = {0, 1, 2, 3};
    int i, j, tmp, dirIndex, nextX, nextY;

    for (i = 0; i < 4; i++) {
        j = rand() % 4;
        tmp = dirOrder[i];
        dirOrder[i] = dirOrder[j];
        dirOrder[j] = tmp;
    }
    for (i = 0; i < 4; i++) {
        dirIndex = dirOrder[i];
        nextX = x + dir[dirIndex][0] * 2;
        nextY = y + dir[dirIndex][1] * 2;
        if (nextX >= 0 && nextX < width && nextY >= 0 && nextY < height && MAZE(nextX, nextY) == 1) {
            MAZE(x + dir[dirIndex][0], y + dir[dirIndex][1]) = 0;
            MAZE(nextX, nextY) = 0;
            generateMaze(maze, width, height, nextX, nextY);
        }
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

    generator.maze.map = malloc(sizeof(int) * generator.maze.width * generator.maze.height);
    generator.seed = time(NULL);
    srand(generator.seed);

    if (generator.status == PERFECT)
        printf("Perfect maze not implemented yet\n");
    else {
        for (int i = 0; i < generator.maze.width * generator.maze.height; i++)
            generator.maze.map[i] = 1;
        generator.maze.map[0] = 0;
        generateMaze(generator.maze.map, generator.maze.width, generator.maze.height, START_X, START_Y);
        generator.maze.map[generator.maze.width * generator.maze.height - 1] = 0;
        printMaze(generator.maze.map, generator.maze.width, generator.maze.height);
    }


    return 0;
}
