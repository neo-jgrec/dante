/*
** EPITECH PROJECT, 2023
** Solver
** File description:
** Main function
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "solver.h"

static _Bool setup_map(char *buffer, map_t *map, size_t file_size)
{
    for (; buffer[MAPW]; MAPW++)
        if (buffer[MAPW] == '\n') {
            buffer[MAPW] = 0; break;
        }
    MAPH = (file_size + 1) / (MAPW + 1);
    MAPM = malloc(sizeof(char *) * (MAPH));
    *MAPM = buffer;
    for (size_t i = 2 * MAPW + 1; (i + 1) / (MAPW + 1) <= MAPH; i += MAPW + 1) {
        MAPM[(i - MAPW) / (MAPW + 1)] = buffer + i - MAPW;
        if (buffer[i] && buffer[i] != '\n') {
            free(buffer);
            return 1;
        } buffer[i] = 0;
    }
    return 0;
}

static void fill_accessible(map_t *map, size_t x, size_t y)
{
    if (MAPM[y][x] == 'X')
        return;
    MAPM[y][x] = 'o';
    if (x > 0)
        FILL_NEXT(x - 1, y);
    if (x < MAPW - 1)
        FILL_NEXT(x + 1, y);
    if (y > 0)
        FILL_NEXT(x, y - 1);
    if (y < MAPH - 1)
        FILL_NEXT(x, y + 1);
}

int solve(FILE *stream)
{
    struct stat s;
    fstat(fileno(stream), &s);
    char *buffer = malloc(s.st_size + 1);
    fread(buffer, s.st_size, sizeof(char), stream);
    buffer[s.st_size] = 0;
    map_t map = {.map = NULL, .height = 0, .width = 0};
    if (setup_map(buffer, &map, s.st_size)) {
        free(buffer);
        return 84;
    }
    fill_accessible(&map, 0, 0);
    for (size_t i = map.width; (i + 1) / (map.width + 1) < map.height + 1; i += map.width + 1)
        buffer[i] = '\n';
    fwrite(buffer, s.st_size + 1, sizeof(char), stdout);
    free(buffer); free(map.map);
    return 0;
}
