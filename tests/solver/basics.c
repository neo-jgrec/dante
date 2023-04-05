/*
** EPITECH PROJECT, 2023
** my_dante
** File description:
** basics
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "malloc_wrapper.h"

int solve(FILE *stream);

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(solver, test1, .init = redirect_all_std)
{
    char *map = "../tests/solver/maps/10_10";

    FILE *stream = fopen(map, "r");
    solve(stream);
    cr_assert_stdout_neq_str("no solution found");
    fclose(stream);
}

Test(solver, test2, .init = redirect_all_std)
{
    char *map = "../tests/solver/maps/no_solution";

    FILE *stream = fopen(map, "r");
    solve(stream);
    cr_assert_stdout_eq_str("no solution found");
    fclose(stream);
}

Test(solver, test3, .init = redirect_all_std)
{
    char *map = "../tests/solver/maps/wrong_map";

    FILE *stream = fopen(map, "r");
    solve(stream);
    cr_assert_stdout_neq_str("no solution found");
    fclose(stream);
}
