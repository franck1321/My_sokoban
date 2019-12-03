/*
** EPITECH PROJECT, 2019
** l
** File description:
** l
*/

#include "../../include/my.h"

int check_bin(int nb)
{
    int bin = 2, zero = 0;

    if (bin == nb) {
        my_putchar('1');
        return (0);
    }
    while (bin < nb) {
        bin = bin * 2;
        zero++;
        if (bin == nb) {
            my_putchar('1');
            while (zero >= 0) {
                my_putchar('0');
                zero--;
            }
            return (0);
        }
    }
    return (1);
}

void my_put_bin(int nb)
{
    int result = 0, check = 0, zero = 0;

    if (nb == 0) {
        my_putchar('0');
        return;
    }
    if (check_bin(nb) == 0)
        return;
    nb < 0 ? my_putchar('-') : 0;
    while (nb > 0 || nb > 1) {
        result = nb % 2;
        result == 0 && check == 0 ? zero = 1 : my_put_nbr(result);
        check = 1;
        nb = nb / 2;
    }
    zero == 1 ? my_put_nbr(0) : 0;
}

int dispatch(va_list list, char flg)
{
    flg == 'c' ? my_putchar(va_arg(list, int)) : 0;
    flg == 'd' || flg == 'i' ? my_put_nbr(va_arg(list, int)) : 0;
    flg == 's' ? my_putstr(va_arg(list, char *)) : 0;
    flg == 'u' ? my_put_nbr_unsigned(va_arg(list, unsigned int)) : 0;
    flg == 'b' ? my_put_bin(va_arg(list, int)) : 0;
    return (0);
}

int format(char *str, int i, int zero)
{
    int i_2 = i, y = 0, sp = 0;
    char *nb = NULL;

    if (zero == 1)
        i++;
    for (; str[i] >= '0' && str[i] <= '9'; i++);
    nb = malloc(sizeof(char) * (i - i_2 + 1));
    for (; str[i_2] >= '0' && str[i_2] <= '9'; i_2++, y++) {
        nb[y] = str[i_2];
    }
    nb[y] = '\0';
    sp = my_getnbr(nb);
    for (; sp != 0; sp--)
        if (zero == 0)
            my_putchar(' ');
        else
            my_putchar('0');
    return (i);
}

int my_printf(char *str, ...)
{
    va_list list;
    int i = 0;

    if (str == NULL)
        return (0);
    va_start(list, str);
    while (str[i] != '\0') {
        if (str[i] == '%') {
            i++;
            str[i] == '0' ? i = format(str, i, 1) : 0;
            str[i] >= '1' && str[i] <= '9' ? i = format(str, i, 0) : 0;
            dispatch(list, str[i]);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
    va_end(list);
    return (i - 1);
}