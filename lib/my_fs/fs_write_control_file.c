/*
** EPITECH PROJECT, 2020
** fs_write_control_file.c
** File description:
** This file contains a function that allow to control output to save state
** into a debug file.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "my_fs.h"
#include "my.h"

int fs_open_debug_file(void)
{
    int fd = -1;

    fd = open("DEBUG_FILE", O_WRONLY | O_APPEND | O_SYNC, 0777);
    if (fd < 0) {
        fd = open("DEBUG_FILE", O_WRONLY | O_CREAT | O_APPEND | O_SYNC, 0777);
        write(fd, "DEBUG FILE\n", 51);
    }
    return (fd);
}

int fs_write_debug_file(char *str_to_write, int nb_to_write)
{
    int fd = fs_open_debug_file();

    if (fd < 0) {
        my_putstr("fail to open/create the debug file\n");
        return (fd);
    }
    write(fd, str_to_write, my_strlen(str_to_write));
    close(fd);
    return (0);
}