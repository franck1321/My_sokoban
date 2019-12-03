/*
** EPITECH PROJECT, 2019
** l
** File description:
** l
*/

#include "../include/my.h"

int check_win(map_s *map)
{
    int y = 0, x = 0, check = 0;

    while (map->map_o[y]) {
        while (map->map_o[y][x] != '\0') {
            if (map->map_o[y][x] == 'O' && map->map[y][x] == 'X')
                check++;
            x++;
        }
        x = 0;
        y++;
    }
    if (check == map->circle)
        return (0);
    return (84);
}

int check_box(map_s *map, int y, int x)
{
    if (map->map[y - 1][x] == '#' && map->map[y][x + 1] == '#')
        return (84);
    if (map->map[y + 1][x] == '#' && map->map[y][x + 1] == '#')
        return (84);
    if (map->map[y + 1][x] == '#' && map->map[y][x - 1] == '#')
        return (84);
    if (map->map[y - 1][x] == '#' && map->map[y][x - 1] == '#')
        return (84);
    return (0);
}

int check_fail(map_s *map)
{
    int y = 0, x = 0, check = 0;

    while (map->map[y]) {
        while (map->map[y][x] != '\0') {
            if (map->map[y][x] == 'X')
                check = check_box(map, y, x);
            x++;
        }
        x = 0;
        y++;
    }
    if (check == 84)
        return (84);
    else
        return (0);
}