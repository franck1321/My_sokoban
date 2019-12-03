/*
** EPITECH PROJECT, 2019
** l
** File description:
** l
*/

#include "../../include/my.h"

void my_print_tab(char **tab)
{
    int y = 0;

    clear();
    while (tab[y]) {
        printw("%s\n", tab[y]);
        y++;
    }
    refresh();
}