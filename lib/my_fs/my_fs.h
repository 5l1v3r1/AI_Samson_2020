/*
** EPITECH PROJECT, 2019
** my_fs.h
** File description:
** This file contains all the files needed for use the lib
*/

#ifndef MY_FS_H
#define MY_FS_H
void fs_cat_x_bytes(char const *filepath, int x);
int fs_get_number_from_first_line(int fd);
int fs_open_file(char const *filepath);
void fs_print_first_line(char const *filepath);
int fs_understand_return_of_read(int fd, char *buffer, int size);
int fs_nb_char_into_file(char *file_name);
int fs_write_debug_file(char *str_to_write, int nb_to_write);
#endif