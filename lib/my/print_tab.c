/*
** EPITECH PROJECT, 2019
** l
** File description:
** l
*/

#include "../../include/my.h"

void my_print_tab(char **tab, WINDOW *win)
{
    int y = 0;
    int a = 1;

    wclear(win);
    box(win, 0, 0);
    while (tab[y]) {
        mvwprintw(win, a, 2, tab[y]);
        //mvwprintw(win, 10, a, "\n");
        a++;
        y++;
    }
    wrefresh(win);
}
