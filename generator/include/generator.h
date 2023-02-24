/*
** EPITECH PROJECT, 2023
** dante
** File description:
** generator
*/

#ifndef GENERATOR_H_
    #define GENERATOR_H_

    #include <stdio.h>
    #include <limits.h>
    #include <string.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <time.h>

    #define EAST 0
    #define SOUTH 1
    #define WEST 2
    #define NORTH 3

    #define VISITED 1
    #define UNVISITED 0
    #define BACKTRACKED 2

    typedef enum direction {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        NONE
    } direction_t;

    typedef enum status {
        PERFECT,
        IMPERFECT
    } status_t;

    typedef struct maze {
        int width;
        int height;
        int **map;
    } maze_t;

    typedef struct generator {
        maze_t maze;
        __uint128_t seed;
        status_t status;
        direction_t direction;
    } generator_t;

#endif /* !GENERATOR_H_ */
