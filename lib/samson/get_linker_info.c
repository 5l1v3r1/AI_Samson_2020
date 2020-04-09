/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** display_linker.c
** File description:
** This file contains all function that allow to print status of linker's
** file functions.
*/

#include "samson.h"

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