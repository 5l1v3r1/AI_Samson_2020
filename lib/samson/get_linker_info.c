/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** display_linker.c
** File description:
** This file contains all function that allow to print status of linker's
** file functions.
*/

#include "samson.h"

int sms_display_link_two_layer_together(int choose, int id_lay1, int id_lay2)
{
    if (choose == 0) {
        write(1, "Linking layer number : ", 23);
        my_put_nbr(id_lay1);
        write(1, ", with layer number : ", 22);
        my_put_nbr(id_lay2);
        return (SUCCESS);
    }
    if (choose == 1) {
        my_putstr(" ==> SUCCESS\n");
        return (SUCCESS);
    }
    my_putstr(" ==> ERROR\n");
    return (ERROR);
}

int proces_link_nrn(layer_t *layer1, neuron_t *nrn_lay2)
{
    for (int n = 0; n < layer1->nb_neuron; n++) {
        if (sms_link_two_neuron_together(layer1, nrn_lay2, n) == ERROR) {
            sms_display_link_two_layer_together(ERROR, 0, 0);
            return (ERROR);
        }
    }
    return (SUCCESS);
}

int sms_display_link_mod(int choose, int found, int want)
{
    if (choose == 0) {
        write(1, "Linking Model...\n", 17);
        return (SUCCESS);
    }
    if (found != want) {
        write(1, "Model Linking : Error\n", 22);
        return(ERROR);
    }
    write(1, "Model Linking : Success\n", 24);
    return (SUCCESS);
}