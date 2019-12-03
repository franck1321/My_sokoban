/*
** EPITECH PROJECT, 2019
** l
** File description:
** l
*/

#include "../include/my.h"

void key_down(map_s *map, int mouv)
{
    if (map->map[map->P_y + 1][map->P_x] == '#')
        return;
    if (map->map[map->P_y + 1][map->P_x] == 'X') {
        if (map->map[map->P_y + 2][map->P_x] == '#' ||
        map->map[map->P_y + 2][map->P_x] == 'X')
            return;
        else {
            mouv++;
            map->P_y += 1;
            map->map[map->P_y][map->P_x] = 'P';
            map->map[map->P_y + 1][map->P_x] = 'X';
        }
    }
    mouv == 0 ? map->P_y += 1 : 0;
    mouv == 0 ? map->map[map->P_y][map->P_x] = 'P' : 0;
    if (map->map_o[map->P_y - 1][map->P_x] == 'O')
        map->map[map->P_y - 1][map->P_x] = 'O';
    else
        map->map[map->P_y - 1][map->P_x] = ' ';
}

void key_up(map_s *map, int mouv)
{
    if (map->map[map->P_y - 1][map->P_x] == '#')
        return;
    if (map->map[map->P_y - 1][map->P_x] == 'X') {
        if (map->map[map->P_y - 2][map->P_x] == '#' ||
        map->map[map->P_y - 2][map->P_x] == 'X')
            return;
        else {
            mouv++;
            map->P_y -= 1;
            map->map[map->P_y][map->P_x] = 'P';
            map->map[map->P_y - 1][map->P_x] = 'X';
        }
    }
    mouv == 0? map->P_y -= 1 : 0;
    mouv == 0 ?map->map[map->P_y][map->P_x] = 'P' : 0;
    if (map->map_o[map->P_y + 1][map->P_x] == 'O')
        map->map[map->P_y + 1][map->P_x] = 'O';
    else
        map->map[map->P_y + 1][map->P_x] = ' ';
}

void key_left(map_s *map, int mouv)
{
    if (map->map[map->P_y][map->P_x - 1] == '#')
        return;
    if (map->map[map->P_y][map->P_x - 1] == 'X') {
        if (map->map[map->P_y][map->P_x - 2] == '#' ||
        map->map[map->P_y][map->P_x - 2] == 'X')
            return;
        else {
            mouv++;
            map->P_x -= 1;
            map->map[map->P_y][map->P_x] = 'P';
            map->map[map->P_y][map->P_x - 1] = 'X';
        }
    }
    mouv == 0? map->P_x -= 1 : 0;
    mouv == 0?map->map[map->P_y][map->P_x] = 'P' : 0;
    if (map->map_o[map->P_y][map->P_x + 1] == 'O')
        map->map[map->P_y][map->P_x + 1] = 'O';
    else
        map->map[map->P_y][map->P_x + 1] = ' ';
}

void key_right(map_s *map, int mouv)
{
    if (map->map[map->P_y][map->P_x + 1] == '#')
        return;
    if (map->map[map->P_y][map->P_x + 1] == 'X') {
        if (map->map[map->P_y][map->P_x + 2] == '#' ||
        map->map[map->P_y][map->P_x + 2] == 'X')
            return;
        else {
            mouv++;
            map->P_x += 1;
            map->map[map->P_y][map->P_x] = 'P';
            map->map[map->P_y][map->P_x + 1] = 'X';
        }
    }
    mouv == 0? map->P_x += 1 : 0;
    mouv == 0? map->map[map->P_y][map->P_x] = 'P' : 0;
    if (map->map_o[map->P_y][map->P_x - 1] == 'O')
        map->map[map->P_y][map->P_x - 1] = 'O';
    else
        map->map[map->P_y][map->P_x - 1] = ' ';
}