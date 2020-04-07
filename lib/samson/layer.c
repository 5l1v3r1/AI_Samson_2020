/*
** BELAHOEUL LABORATORY'S PROJECT, 2020
** layer.c
** File description:
** This file contains all the functions that allow to build layers.
*/

#include "samson.h"

layer_t *sms_prepare_new_layer(layer_t *new_layer, int id)
{
    new_layer->id = id;
    new_layer->nb_neuron = 0;
    new_layer->first = NULL;
    new_layer->next = NULL;
    return (new_layer)
}

int sms_add_layer(model_t *model, int nb_neuron)
{
    layer_t *new_layer = malloc(sizeof(layer_t));
    layer_t *current_layer = NULL;

    if (model == NULL || new_layer == NULL)
        return (ERROR);
    new_layer = sms_prepare_new_layer(new_layer, model->nb_layers);
    for (; new_layer->nb_neuron < nb_neuron; new_layer->nb_neuron++) {
        if (sms_add_neuron(new_layer, new_layer->nb_neuron) == ERROR)
            return (ERROR);
    }
    current_layer = model->first;
    while (current_layer != NULL && current_layer->next != NULL)
        current_layer = current_layer->next;
    if (current_layer == NULL)
        model->first = new_layer;
    else
        current_layer->next = new_layer;
    model->nb_layers += 1;
    return (SUCCESS);
}