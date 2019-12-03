/*
** EPITECH PROJECT, 2019
** l
** File description:
** l
*/

#include "../../include/my.h"

char *my_itoa(int nb)
{
    int i, cpt;
    char *res;

    for (i = 1, cpt = 1; nb / i >= 10; i *= 10, cpt++);
    res = malloc(sizeof(*res) * (cpt + 1));
    for (cpt = 0; i; cpt++, i /= 10)
        res[cpt] = (nb / i) % 10 + '0';
    res[cpt] = '\0';
    return (res);
}