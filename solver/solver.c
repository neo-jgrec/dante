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
        if (buffer[MAPW] == '\n' || !buffer[MAPW])
            break;
    MAPH = (file_size + 1) / (MAPW + 1);
    for (size_t i = 2 * MAPW + 1; (i + 1) / (MAPW + 1) <= MAPH; i += MAPW + 1)
        if (buffer[i] && buffer[i] != '\n')
            return 1;
    return 0;
}

static _Bool backtrack(map_t *map, size_t x, size_t y)
{
    if (x == MAPW - 1 && y == MAPH - 1) {
        map->map[y * (MAPW + 1) + x] = 'o';
        return 1;
    }
    if (x < MAPW - 1 && map->map[y * (MAPW + 1) + x + 1] == '*')
        if (backtrack(map, x + 1, y)) {
            map->map[y * (MAPW + 1) + x] = 'o';
            return 1;
        }
    if (y < MAPH - 1 && map->map[(y + 1) * (MAPW + 1) + x] == '*')
        if (backtrack(map, x, y + 1)) {
            map->map[y * (MAPW + 1) + x] = 'o';
            return 1;
        }
    return 0;
}

int solve(FILE *stream)
{
    struct stat s;
    fstat(fileno(stream), &s);
    char *buffer = malloc(s.st_size + 1);
    fread(buffer, s.st_size, sizeof(char), stream);
    buffer[s.st_size] = 0;
    map_t map = {.map = buffer, .height = 0, .width = 0};
    if (setup_map(buffer, &map, s.st_size)) {
        free(buffer); return 84;
    }
    backtrack(&map, 0, 0);
    for (size_t i = map.width; (i + 1) / (map.width + 1) < map.height + 1; i += map.width + 1)
        buffer[i] = '\n';
    fwrite(buffer, s.st_size, sizeof(char), stdout);
    free(buffer);
    return 0;
}
