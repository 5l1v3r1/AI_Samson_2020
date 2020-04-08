/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** compil_model.c
** File description:
** This file contains all the function that allow to compil and test the model.
*/

#include "samson.h"

int sms_try_layers(model_t *model, int nb_layers_expected)
{
    int result = SUCCESS;
    int layers_found = 0;

    write(1, "Verifying layers...\n", 20);
    if (model == NULL || model->first == NULL)
        return (ERROR);
    for (; sms_find_layer_by_id(model, layers_found) != NULL; layers_found++);
    if (layers_found != nb_layers_expected) {
        write(1, "Model Error : Number layers incorrect : Expected : ", 51);
        result = ERROR;
    } else
        write(1, "Model Sucess : Number layers correct : Expected : ", 50);
    my_put_nbr(nb_layers_expected);
    write(1, ", Found : ", 10);
    my_put_nbr(layers_found);
    my_putchar('\n');
    return (SUCCESS);
}

int sms_try_neurons(model_t *model)
{
    int nrn_found = 0;
    layer_t *current = NULL;

    write(1, "Verifying neurons...\n", 21);
    if (model == NULL || model->first == NULL)
        return (ERROR);
    for (int i = 0; i < model->nb_layers; i++) {
        current = sms_find_layer_by_id(model, i);
        write(1, "Layer number : ", 15);
        my_put_nbr(i);
        if (current == NULL)
            return (ERROR);
        nrn_found = 0;
        for (; sms_find_neuron_by_id(current, nrn_found) != NULL; nrn_found++);
        write(1, " : Number neurons : Expected : ", 31);
        my_put_nbr(current->nb_neuron);
        write(1, ", Found : ", 10);
        my_put_nbr(nrn_found);
        if (nrn_found != current->nb_neuron) {
            write(1, " ==> Layer Error\n", 17);
            return (ERROR);
        }
        write (1, " ==> Layer Success\n", 19);
    }
    return (SUCCESS);
}

int sms_try_model(model_t *model)
{
    int result = SUCCESS;

    write(1, "Verifying model...\n", 19);
    if (model == NULL || model->first == NULL)
        result = ERROR;
    result = sms_try_layers(model, model->nb_layers);
    if (result == ERROR)
        return (ERROR);
    result = sms_try_neurons(model);
    return (result);
}

int sms_compile_model(model_t *model)
{
    write(1, "Using Samson, made by Sofian Belahouel.\n", 40);
    if (sms_try_model(model) == ERROR) {
        write(1, "Model Compilation : Error\n", 27);
        return (ERROR);
    }
    write(1, "Model Compilation : Success\n", 28);
    return (SUCCESS);
}

int sms_get_ml_output(model_t *model)
{

}

int sms_fit_model(model_t *model, int generation, char *activation, float *inp, int lngt)
{
    if (sms_compile_model(model) == ERROR)
        return (ERROR);
    for (int i = 0; i < generation; i++) {
        if (sms_fill_dataset_user(model, inp, lngt) == ERROR)
            return (ERROR);
            //JE DOIS FAIRE FILL RESULT
        if (sms_link_model(model) == ERROR);
            return (ERROR);
        sms_get_ml_output(model);
    }
}