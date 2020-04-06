/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** print_model.c
** File description: This file contains a function that allow to visualize
** the model.
*/

#include "samson.h"

void sms_print_layer_model(model_t *model)
{
    layer_t *current = NULL;

    if (model != NULL) {
        current = model->first;
        while (current != NULL) {
            my_put_nbr(current->id);
            my_putstr(" -> ");
            current = current->next;
        }
        my_putstr("NULL\n");
    }
}

void sms_print_neuron_layer(layer_t *layer)
{
    neuron_t *current = NULL;

    if (layer != NULL) {
        current = layer->first;
        while (current != NULL) {
            my_putstr("O\n|\nV\n");
            current = current->next;
        }
        my_putstr("NULL\n");
    }
}