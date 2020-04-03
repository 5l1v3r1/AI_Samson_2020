/*
** EPITECH PROJECT, 2019
** task01_my.h
** File description:
** prototypes of the function in the lib
*/

#ifndef MY_H
#define MY_H

#define TRUE 1
#define EXP 2.718281828459045

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec( int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int matching(char *str, char const *to_find, int i);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int *my_mallocer_int(int lenth_wanted);
char *my_mallocer_char(int lenth_wanted);
int my_tab_char_isneg(char *src);
int my_transform_char_into_digit(char nb);
int my_str_to_digit(char *str);
char *my_int_to_str(int nb);
int my_nbrlen(int nbr);
char *my_strdup(char *str);
int my_error(const char *str);
int my_put_unsint(unsigned int number);
int my_put_double(char *str);
double my_transform_char_into_double(char *str);
void tab_of_point_on_func(int (*tab_point[])(char *));
char **my_str_to_word_array(char *str, int slash_mode_on);
int my_biggest_word_into_buff(char *buff, char stop);
char **my_file_to_dbl_array(char *file_name);
int my_count_wrd_into_buff(char *str, char stop);
float my_exp(float nb);

#endif
