/*
** EPITECH PROJECT, 2023
** Solver
** File description:
** Main header
*/

#ifndef SOLVER_H_
    #define SOLVER_H_

    #include <stddef.h>

    #define MAPW map->width
    #define MAPH map->height

typedef struct map_s {
    char *map;
    size_t height;
    size_t width;
} map_t;

int solve(FILE *stream);

#endif /* !SOLVER_H_ */
