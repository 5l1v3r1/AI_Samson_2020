/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** linker.c
** File description:
** This file contains a function that allow to link two layer.
*/

#include "samson.h"

int sms_link_two_neuron_together(layer_t *layer1, neuron_t *nrn2, int n)
{
    neuron_t *nrn1 = NULL;

    nrn1 = sms_find_neuron_by_id(layer1, n);
    if (nrn1 == NULL) {
        sms_display_link_two_layer_together(ERROR, 0, 0);
        return (ERROR);
    }
    printf("weight = %f\n", nrn2->weight[n]);
    nrn2->som = sms_somme(nrn2->som, nrn1->prob, nrn2->weight[n]);
    nrn2->prob = sms_activation(nrn2->som);
    printf("probability = %f  * %f\n", nrn1->prob, nrn2->weight[n]);
    return (SUCCESS);
}

int sms_link_two_layer_together(layer_t *layer1, layer_t *layer2)
{
    neuron_t *nrn_lay1 = NULL;
    neuron_t *nrn_lay2 = NULL;

    if (layer1 == NULL || layer1->first == NULL || layer1->nb_neuron == 0
    || layer2 == NULL || layer2->first == NULL || layer2->nb_neuron == 0)
        return (ERROR);
    sms_display_link_two_layer_together(0, layer1->id, layer2->id);
    for (int i = 0; i < layer2->nb_neuron; i++) {
        nrn_lay2 = sms_find_neuron_by_id(layer2, i);
        if (nrn_lay2 == NULL) {
            sms_display_link_two_layer_together(ERROR, 0, 0);
            return (ERROR);
        }
        if (proces_link_nrn(layer1, nrn_lay2) == ERROR)
            return (ERROR);
    }
    printf("Somme = %f\n", nrn_lay2->som);
    printf("Activation = %f\n", nrn_lay2->prob);
    sms_display_link_two_layer_together(TRUE, 0, 0);
    return (SUCCESS);
}

int sms_fill_dataoutput_mlresult(model_t *model)
{
    layer_t *output_layer = NULL;

    if (model == NULL || model->first == NULL || model->output_set == NULL) {
        write(1, "Model Error : Dataset : Check your RAM\n", 48);
        return (ERROR);
    }
    write(1, "Collecting Machine Learning Result in output layer\n", 51);
    output_layer = sms_find_layer_by_id(model, model->nb_layers);
    if (output_layer == NULL || output_layer->first == NULL)
        return (ERROR);
    for (int i = 0; i < model->nb_output; i++)
        model->output_set[i] = sms_get_proba_into_neuron(output_layer, i);
    return (SUCCESS);
}

int sms_link_model(model_t *model)
{
    layer_t *layer1 = NULL;
    layer_t *layer2 = NULL;
    int i = 0;
    int result = SUCCESS;

    if (model == NULL || model->first == NULL)
        return (ERROR);
    sms_display_link_mod(0, 0, 0);
    for (; i < model->nb_layers; i++) {
        if (i > 0) {
            layer1 = sms_find_layer_by_id(model, i - 1);
            layer2 = sms_find_layer_by_id(model, i);
            if (layer1 == NULL || layer2 == NULL)
                break;
            if (sms_link_two_layer_together(layer1, layer2) == ERROR)
                return (ERROR);
            if (i == model->nb_layers - 1
            && sms_fill_dataoutput_mlresult(model) == ERROR)
                return (ERROR);
        }
    }
    result = sms_display_link_mod(1, i, model->nb_layers);
    return (result);
}