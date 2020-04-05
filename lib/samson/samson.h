/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** samson.h
** File description:
** This file contains all the prototypes needed to use Samson library.
*/

#ifndef SAMSON_H
#define SAMSON_H

                                                                         //start CONST AND DEFINE
#define TRUE          1                                                        //CONST AND DEFINE
#define FALSE         0                                                        //CONST AND DEFINE
#define EXP           2.718281828459045                                        //CONST AND DEFINE
#define EULER         2.718281                                                 //CONST AND DEFINE
#define LEARNING_RATE 0.5                                                      //CONST AND DEFINE
#define EPITECH_ERROR 84                                                       //CONST AND DEFINE
#define SUCCES        0                                                        //CONST AND DEFINE
                                                                           //end CONST AND DEFINE

                                                                         //start PROTOTYPES LIB MY
void my_putchar(char c);                                                       //PROTOTYPES LIB MY
int my_isneg(int nb);                                                          //PROTOTYPES LIB MY
int my_put_nbr(int nb);                                                        //PROTOTYPES LIB MY
void my_swap(int *a, int *b);                                                  //PROTOTYPES LIB MY
void my_putstr(char const *str);                                               //PROTOTYPES LIB MY
int my_strlen(char const *str);                                                //PROTOTYPES LIB MY
int my_getnbr(char const *str);                                                //PROTOTYPES LIB MY
void my_sort_int_array(int *tab, int size);                                    //PROTOTYPES LIB MY
int my_compute_power_rec( int nb, int power);                                  //PROTOTYPES LIB MY
int my_compute_square_root(int nb);                                            //PROTOTYPES LIB MY
int my_is_prime(int nb);                                                       //PROTOTYPES LIB MY
int my_find_prime_sup(int nb);                                                 //PROTOTYPES LIB MY
char *my_strcpy(char *dest, char const *src);                                  //PROTOTYPES LIB MY
char *my_strncpy(char *dest, char const *src, int n);                          //PROTOTYPES LIB MY
char *my_revstr(char *str);                                                    //PROTOTYPES LIB MY
int matching(char *str, char const *to_find, int i);                           //PROTOTYPES LIB MY
char *my_strstr(char *str, char const *to_find);                               //PROTOTYPES LIB MY
int my_strcmp(char const *s1, char const *s2);                                 //PROTOTYPES LIB MY
int my_strncmp(char const *s1, char const *s2, int n);                         //PROTOTYPES LIB MY
char *my_strupcase(char *str);                                                 //PROTOTYPES LIB MY
char *my_strlowcase(char *str);                                                //PROTOTYPES LIB MY
char *my_strcapitalize(char *str);                                             //PROTOTYPES LIB MY
int my_str_isalpha(char const *str);                                           //PROTOTYPES LIB MY
int my_str_isnum(char const *str);                                             //PROTOTYPES LIB MY
int my_str_islower(char const *str);                                           //PROTOTYPES LIB MY
int my_str_isupper(char const *str);                                           //PROTOTYPES LIB MY
int my_str_isprintable(char const *str);                                       //PROTOTYPES LIB MY
int my_showstr(char const *str);                                               //PROTOTYPES LIB MY
int my_showmem(char const *str, int size);                                     //PROTOTYPES LIB MY
char *my_strcat(char *dest, char const *src);                                  //PROTOTYPES LIB MY
char *my_strncat(char *dest, char const *src, int nb);                         //PROTOTYPES LIB MY
int *my_mallocer_int(int lenth_wanted);                                        //PROTOTYPES LIB MY
char *my_mallocer_char(int lenth_wanted);                                      //PROTOTYPES LIB MY
int my_tab_char_isneg(char *src);                                              //PROTOTYPES LIB MY
int my_transform_char_into_digit(char nb);                                     //PROTOTYPES LIB MY
int my_str_to_digit(char *str);                                                //PROTOTYPES LIB MY
char *my_int_to_str(int nb);                                                   //PROTOTYPES LIB MY
int my_nbrlen(int nbr);                                                        //PROTOTYPES LIB MY
char *my_strdup(char *str);                                                    //PROTOTYPES LIB MY
int my_error(const char *str);                                                 //PROTOTYPES LIB MY
int my_put_unsint(unsigned int number);                                        //PROTOTYPES LIB MY
int my_put_double(char *str);                                                  //PROTOTYPES LIB MY
double my_transform_char_into_double(char *str);                               //PROTOTYPES LIB MY
void tab_of_point_on_func(int (*tab_point[])(char *));                         //PROTOTYPES LIB MY
char **my_str_to_word_array(char *str, int slash_mode_on);                     //PROTOTYPES LIB MY
int my_biggest_word_into_buff(char *buff, char stop);                          //PROTOTYPES LIB MY
char **my_file_to_dbl_array(char *filename, char parser);                      //PROTOTYPES LIB MY
int my_count_wrd_into_buff(char *str, char stop);                              //PROTOTYPES LIB MY
                                                                           //end PROTOTYPES LIB MY

                                                                         //start PROTOTYPES LIB MY_FS
void fs_cat_x_bytes(char const *filepath, int x);                              //PROTOTYPES LIB MY_FS
int fs_get_number_from_first_line(int fd);                                     //PROTOTYPES LIB MY_FS
int fs_open_file(char const *filepath);                                        //PROTOTYPES LIB MY_FS
void fs_print_first_line(char const *filepath);                                //PROTOTYPES LIB MY_FS
int fs_understand_return_of_read(int fd, char *buffer, int size);              //PROTOTYPES LIB MY_FS
int fs_nb_char_into_file(char *file_name);                                     //PROTOTYPES LIB MY_FS
int fs_write_debug_file(char *str_to_write, int nb_to_write);                  //PROTOTYPES LIB MY_FS
                                                                           //end PROTOTYPES LIB MY_FS

                                                                         //start PROTOTYPES LIB SAMSON
int sms_random_gen_int(int min, int max);                                          //PROTOTYPES LIB SAMSON
float sms_random_float(float min, float max, int nb_dec);                      //PROTOTYPES LIB SAMSON
float sms_xposant_ten(float number, int xposant);                              //PROTOTYPES LIB SAMSON
char **sms_open_csv(char *filename);                                           //PROTOTYPES LIB SAMSON
float sms_exp(float nb);                                                       //PROTOTYPES LIB SAMSON
                                                                           //end PROTOTYPES LIB SAMSON

#endif