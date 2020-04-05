/*
** EPITECH PROJECT, 2019
** task00_my_strcat
** File description:
** je ne sais pas
*/

#include "samson.h"
#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
    int lenght_src = my_strlen(src);
    int lenght_dest = my_strlen(dest);
    char *final = NULL;

    final = malloc(sizeof(char) * (lenght_dest + lenght_src + 1));
    if (final != NULL) {
        for (int i = 0; i < lenght_dest + lenght_src; i++)
            final[i] = 0;
        for (int i = 0; i < lenght_dest; i++)
            final[i] = dest[i];
        for (int i = 0; i < lenght_src; i++)
            final[lenght_dest + i] = src[i];
    }
    return (final);
}
