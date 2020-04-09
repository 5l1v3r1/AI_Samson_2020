/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** model.c
** File description:
** This file contains all the functions that allow to build models.
*/

#include "samson.h"

float *sms_prepare_dataset(float *dataset, int lenght)
{
    dataset = malloc(sizeof(float) * (lenght + 1));

    if (dataset == NULL)
        return (NULL);
    for (int i = 0; i < lenght; i++)
        dataset[i] = 0.0;
    return (dataset);
}

int sms_give_input_first_lay(model_t *model)
{
    layer_t *input_lay = NULL;
    neuron_t *neuron = NULL;

    if (model == NULL || model->input_set == NULL || model->first == NULL)
        return (ERROR);
    input_lay = model->first;
    if (input_lay->first == NULL)
        return (ERROR);
    neuron = input_lay->first;
    if (neuron == NULL)
        return (ERROR);
    for (int i = 0; i < model->nb_input - 1; i++) {
        if (neuron->next == NULL)
            return (ERROR);
        neuron->prob = model->input_set[i];
        neuron = neuron->next;
    }
    return (SUCCESS);
}

int sms_fill_dataset_user(model_t *model, float *user_dtset, int lenght_u)
{
    if (model == NULL || model->input_set == NULL || user_dtset == NULL) {
        write(1, "Model Error : Dataset : Check your input or RAM\n", 48);
        return (ERROR);
    } else if (model->nb_input != lenght_u) {
        write(1, "Model : Error : Expected : ", 27);
        my_put_nbr(model->nb_input);
        write(1, " input(s), Got : ", 17);
        my_put_nbr(lenght_u);
        write(1, " input(s)\n", 10);
        return (ERROR);
    }
    for (int i = 0; i < model->nb_input; i++) {
        if (user_dtset[i] < 0.0 || user_dtset[i] > 1.0) {
            write(1, "Model Error : Dataset should be only digits betwee", 50);
            write(1, "n 0 and 1\n", 10);
            return (ERROR);
        }
        model->input_set[i] = user_dtset[i];
    }
    if (sms_give_input_first_lay(model) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

int sms_prepare_model(model_t *model, int nb_input, int nb_output)
{
    if (model == NULL)
        return (ERROR);
    model->gradient = NULL;
    model->biais = 0;
    model->learning_rate = LEARNING_RATE;
    model->nb_layers = 0;
    model->nb_input = nb_input;
    model->nb_output = nb_output;
    model->input_set = NULL;
    model->output_set = NULL;
    model->result_wanted = NULL;
    model->input_set = sms_prepare_dataset(model->input_set, nb_input);
    model->output_set = sms_prepare_dataset(model->output_set, nb_output);
    model->gradient = sms_prepare_dataset(model->gradient, nb_output);
    if (model->input_set == NULL || model->output_set == NULL
    || model->gradient == NULL)
        return (ERROR);
    return (SUCCESS);
}

model_t *sms_init_model(int nb_input, int nb_output)
{
    model_t *model = malloc(sizeof(model_t));

    if (model == NULL)
        return (NULL);
    model->first = NULL;
    if (sms_prepare_model(model, nb_input, nb_output) == ERROR)
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
    free(model->gradient);
    free(model->input_set);
    free(model->output_set);
    free(current);
    free(model);
    return (SUCCESS);
}