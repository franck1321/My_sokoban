/*
** EPITECH PROJECT, 2019
** /
** File description:
** /
*/

#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int   mod;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    if (nb >= 0) {
        if (nb >= 10) {
            mod = (nb % 10);
            nb = (nb - mod) / 10;
            my_put_nbr(nb);
            my_putchar(48 + mod);
        }
        else
            my_putchar(48 + nb % 10);
    }
    return (0);
}

int my_put_nbr_unsigned(unsigned int nb)
{
    unsigned int mod;

    if (nb >= 10) {
        mod = (nb % 10);
        nb = (nb - mod) / 10;
        my_put_nbr(nb);
        my_putchar(48 + mod);
    }
    else
        my_putchar(48 + nb % 10);
    return (0);
}