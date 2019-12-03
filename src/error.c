/*
** EPITECH PROJECT, 2019
** l
** File description:
** l
*/

#include "../include/my.h"

void h(void)
{
    write(1, "USAGE\n\t./my_sokoban map\nDESCRIPTION\n\tmap file", 46);
    write(1, "representing the warehouse map, containing '#' for ", 52);
    write(1, "walls,\n\t'P' for the player, 'X' for boxes and 'O' for", 55);
    write(1, " storage locations.", 20);
}

int count_char(map_s *map, int x, int y)
{
    if (map->map[y][x] == 'P') {
        map->player++;
        return (0);
    }
    if (map->map[y][x] == 'X') {
        map->box++;
        return (0);
    }
    if (map->map[y][x] == 'O') {
        map->circle++;
        return (0);
    }
    if (map->map[y][x] == ' ' || map->map[y][x] == '\n')
        return (0);
    if (map->map[y][x] == '#') {
        map->wall++;
        return (0);
    }
    return (84);
}

int error(map_s *map)
{
    int error = 0;

    if (map->player != 1) {
        write (2, "Only one player accepted", 25);
        error++;
    }
    if (map->box != map->circle || map->box < 1 || map->circle < 1) {
        write(2, "box ans circle must be equal", 29);
        error++;
    }
    if (map->wall < 12) {
        write(2, "map ivalid", 11);
        error++;
    }
    if (error != 0)
        return (84);
    else
        return (0);
}

int check_map(map_s *map)
{
    int x = 0;
    int y = 0;

    while (map->map[y]) {
        while (map->map[y][x] != '\0') {
            count_char(map, x, y);
            x++;
        }
        x = 0;
        y++;
    }
    if (error(map) == 84)
        return (84);
    else
        return (0);
}

