/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** display_fit.c
** File description:
** This file cotains a function that allow to display training in runtime.
*/

#include "samson.h"

char *sms_fit_lines(char *str, int lenght)
{
    for (int i = 0; i < lenght; i++)
        str[i] = '=';
    return (str);
}

void sms_display_first_end_line(char *display_lines, int end)
{
    if (end == FALSE) {
        my_putstr(display_lines);
        my_putstr("START_TRAINING");
        my_putstr(display_lines);
        my_putchar('\n');
    } else {
        my_putstr(display_lines);
        my_putstr("=END_TRAINING=");
        my_putstr(display_lines);
        my_putchar('\n');
    }
}

int sms_display_model(int cur_gen, int tot_gen, int end)
{
    int gen_lenght = my_nbrlen(tot_gen) + 58;
    char *display_lines = NULL;
    int nb_eq_disp = (gen_lenght - 16) / 2;

    if (nb_eq_disp <= 0)
        return (ERROR);
    display_lines = malloc(sizeof(char) * (nb_eq_disp + 1));
    if (display_lines == NULL)
        return (ERROR);
    display_lines = sms_clean_array(display_lines, nb_eq_disp + 1);
    display_lines = sms_fit_lines(display_lines, nb_eq_disp);
    if (display_lines == NULL)
        return (ERROR);
    sms_display_first_end_line(display_lines, end);
    free(display_lines);
    return (SUCCES);
}