/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** model.c
** File description:
** This file contains all the functions that allow to build models.
*/

#include "samson.h"

int sms_prepare_model(model_t *model)
{
    if (model == NULL)
        return (ERROR);
    model->nb_layers = 0;
    model->nb_input = 0;
    model->nb_output = 0;
    return (SUCCESS);
}

model_t *sms_init_model(void)
{
    model_t *model = malloc(sizeof(model_t));

    if (model == NULL)
        return (NULL);
    model->first = NULL;
    if (sms_prepare_model(model) == ERROR)
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