/*
** EPITECH PROJECT, 2019
** l
** File description:
** l
*/


#ifndef MY_H
#define MY_H

/* Fonction Lib/My + Lib */

#include <fcntl.h>
#include <ncurses.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>


int my_getnbr(char *str);
int my_isneg(int n);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char *str);
char *my_evil_str(char *str);
void my_sort_int_array(int *array, int size);
char *my_strcapitalize(char *str);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char *src);
int my_str_isalpha(char const *str);
int my_str_islower(char const *str);
int my_str_isnum(char const *str);
int my_str_isprintable(char const *str);
int my_strlen(char const *str);
char *my_strlowcase(char *str);
int my_strncmp(char *s1, char *s2, int n);
char *my_strncpy(char *dest, char *src, int n);
char *my_strstr(char *str, char const *to_find);
char *my_strupcase(char *str);
void my_swap(int *a, int *b);
char *my_strdup(char const *str);
char *my_revstr(char *str);
char *open_file(char *filepath);
void put_in_array(char const *str, char **av);
char **my_str_to_word_array(char const *str);
int word_len(const char *str, int i);
int word_count(const char *str);
void my_print_tab(char **tab);
int my_put_nbr_unsigned(unsigned int nb);
int my_printf(char *str, ...);

/* Fonction Du program */

typedef struct struct_t {
    char **map;
    char **map_o;
    int P_y;
    int P_x;
    int check;
    int box;
    int circle;
    int wall;
    int player;
} map_s;

void h(void);
int count_char(map_s *map, int x, int y);
int error(map_s *map);
int check_map(map_s *map);
void key_right(map_s *map, int mouv);
void key_left(map_s *map, int mouv);
void key_up(map_s *map, int mouv);
void key_down(map_s *map, int mouv);
void pos_player(map_s *map);
void mouvement(int key, map_s *map);
int game(map_s *map);
int check_win(map_s *map);
int check_box(map_s *map, int y, int x);
int check_fail(map_s *map);

/*         END          */

#endif /* MY_H */

