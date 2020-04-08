/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** model.c
** File description:
** This file contains all the functions that allow to build models.
*/

#include "samson.h"

int sms_prepare_model(model_t *model, int nb_input, int nb_output)
{
    if (model == NULL)
        return (ERROR);
    model->gradient = 0.0;
    model->biais = 0;
    model->learning_rate = 0.5;
    model->nb_layers = 0;
    model->nb_input = nb_input;
    model->nb_output = nb_output;
    return (SUCCESS);
}

model_t *sms_init_model(int nb_input, int nb_output)
{
    model_t *model = malloc(sizeof(model_t));

    if (model == NULL)
        return (NULL);
    model->first = NULL;
    if (sms_prepare_model(model, 2, 1) == ERROR)
        return (NULL);
    return (model);
}

int sms_rm_model(model_t *model)
{
    layer_t *current = NULL;
    layer_t *to_rm = NULL;

    if (model == NULL || model->first == NULL)
        return (ERROR);
    current = model->first;
    while (current->next != NULL) {
        to_rm = current;
        sms_rm_neuron(current);
        current = current->next;
        free(to_rm);
    }
    sms_rm_neuron(current);
    free(current);
    free(model);
    return (SUCCESS);
}