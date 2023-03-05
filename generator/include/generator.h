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
    #include <stdbool.h>
    #include <stdint.h>

    typedef enum status {
        PERFECT,
        IMPERFECT
    } status_t;

    typedef struct vector2i {
        int x;
        int y;
    } vector2i_t;

    typedef struct maze {
        vector2i_t size;
        char *map;
    } maze_t;

    typedef struct generator {
        maze_t maze;
        status_t status;
        uint64_t seed;
    } generator_t;

    char *maze_generation(int x, int y, status_t status);

#endif /* !GENERATOR_H_ */
