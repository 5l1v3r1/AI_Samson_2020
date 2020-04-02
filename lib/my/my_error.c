/*
** EPITECH PROJECT, 2019
** my_error.c
** File description:
** This function manage the stderr
*/

#include <unistd.h>
#include "my.h"

int my_error(const char *str)
{
    int index = 0;
    int lenght = my_strlen(str);

    while (str[index] != '\0') {
        write(2, str, lenght);
        index++;
    }
    return (84);
}