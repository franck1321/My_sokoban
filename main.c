/*
** EPITECH PROJECT, 2019
** l
** File description:
** l
*/

#include "include/my.h"

void pos_player(map_s *map)
{
    int y = 0, x = 0;

    while (map->map[y]) {
        while (map->map[y][x] != '\0') {
            if (map->map[y][x] == 'P') {
                map->P_x = x;
                map->P_y = y;
                return;
            }
            x++;
        }
        x = 0;
        y++;
    }
}

void mouvement(int key, map_s *map)
{
    int mouv = 0;

    pos_player(map);
    my_print_tab(map->map);
    key = getch();
    key == KEY_DOWN ? key_down(map, mouv) : 0;
    key == KEY_UP ? key_up(map, mouv) : 0;
    key == KEY_RIGHT ? key_right(map, mouv) : 0;
    key == KEY_LEFT ? key_left(map, mouv) : 0;
}

int check_fail_or_win(map_s *map)
{
    if (check_win(map) == 0) {
        endwin();
        write(1, "You Win !", 10);
        free(map);
        return (0);
    }
}

int map_height(map_s *map)
{
    int y = 0;

    while (map->map[y])
        y++;
    return (y + 2);
}

int map_width(map_s *map)
{
    int y = 0, len_line = 0, len_box = 0;

    while (map->map[y]) {
        len_line = my_strlen(map->map[y]);
        if (len_line > len_box)
            len_box = len_line;
        y++;
    }
    return (len_box + 4);
}

int game(map_s *map)
{
    int i = 0, key = 0, mouv = 0;

    initscr();
    keypad(stdscr, TRUE);
    while (i != 32) {
        mouvement(key, map);
        if (check_fail(map) == 84) {
            endwin();
            write(1, "You Loose !", 12);
            free(map);
            return (84);
        }
        if (check_fail_or_win(map) == 0)
            return (0);
        refresh();
    }
}

int main(int ac, char **av, char **env)
{
    char *file;
    map_s *map = malloc(sizeof(map_s));

    if (ac != 2)
        return (84);
    if (av[1][0] == '-' && av[1][1] == 'h') {
        h();
        return (0);
    }
    file = open_file(av[1]);
    map->map = my_str_to_word_array(file);
    map->map_o = my_str_to_word_array(file);
    if (check_map(map) == 84)
        return (84);
    if (game(map) == 84)
        return (1);
    return (0);
}