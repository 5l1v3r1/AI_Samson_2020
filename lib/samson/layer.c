/*
** BELAHOEUL LABORATORY'S PROJECT, 2020
** layer.c
** File description:
** This file contains all the functions that allow to build layers.
*/

#include "samson.h"

int sms_add_layer(model_t *model, int nb_neuron, int id)
{
    layer_t *new_layer = malloc(sizeof(layer_t));
    layer_t *current_layer = NULL;

    if (model == NULL || new_layer == NULL)
        return (ERROR);
    new_layer->id = id;
    new_layer->nb_neuron = nb_neuron;
    new_layer->first = NULL;
    new_layer->next = NULL;
    for (int i = 0; i < nb_neuron; i++)
        if (sms_add_neuron(new_layer, i) == ERROR)
            return (ERROR);
    current_layer = model->first;
    while (current_layer != NULL && current_layer->next != NULL) {
        current_layer = current_layer->next;
    }
    if (current_layer == NULL)
        model->first = new_layer;
    else
        current_layer->next = new_layer;
    return (SUCCES);
}