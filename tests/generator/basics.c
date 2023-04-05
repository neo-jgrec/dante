/*
** EPITECH PROJECT, 2023
** my_dante
** File description:
** basics
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "generator.h"
#include "malloc_wrapper.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(generator, print_maze1, .init = redirect_all_std)
{
    print_maze("******************************************************************************************", 9, 10);
    cr_assert_stdout_eq_str("*********\n*********\n*********\n*********\n*********\n*********\n*********\n*********\n*********\n*********");
}

Test(generator, print_maze_null, .init = redirect_all_std)
{
    print_maze(NULL, 10, 10);
    cr_assert_stdout_eq_str("");
}

Test(generator, maze_generation_imperfect, .init = redirect_all_std)
{
    cr_assert_neq(maze_generation(10, 10, IMPERFECT), NULL);
}

Test(generator, maze_generation_perfect, .init = redirect_all_std)
{
    cr_assert_neq(maze_generation(10, 10, PERFECT), NULL);
}

Test(generator, maze_generation_malloc_fail, .init = redirect_all_std)
{
    break_malloc();
    cr_assert_eq(maze_generation(10, 10, PERFECT), NULL);
    fix_malloc();
}