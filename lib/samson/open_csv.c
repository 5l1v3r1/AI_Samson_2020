/*
** BELAHOUEL INDUSTRIES'S PROJECT, 2020
** open_csv.c
** File description:
** This file contains a function that open a csv file.
*/

#include "samson.h"
#include <unistd.h>

char **sms_open_csv(char *filename)
{
    char **file = NULL;

    file = my_file_to_dbl_array(filename, ',');
    return (file);
}