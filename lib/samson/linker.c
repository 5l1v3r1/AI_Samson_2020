/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** linker.c
** File description:
** This file contains a function that allow to link two layer.
*/

#include "samson.h"

int sms_link_two_neuron_together(neuron_t *nrn_layer1, neuron_t *nrn_layer2)
{

}

int sms_link_two_layer_together(layer_t *layer1, layer_t *layer2)
{
    neuron_t *nrn_lay1 = NULL;
    neuron_t *nrn_lay2 = NULL;

    if (layer1 == NULL || layer1->first == NULL || layer1->nb_neuron == 0
    || layer2 == NULL || layer2->first == NULL || layer2->nb_neuron == 0)
        return (ERROR);
    write(1, "Starting to link layer number : ", 32);
    my_put_nbr(layer1->id);
    write(1, ", with layer number : ", 22);
    my_put_nbr(layer2->id);
    my_putchar('\n');
    for (int i = 0; i < layer2->nb_neuron; i++) {
        nrn_lay2 = sms_find_neuron_by_id(layer2, i);
        for (int n = 0; n < layer1->nb_neuron; n++) {
            nrn_lay1 = sms_find_neuron_by_id(layer1, n);
            printf("weight = %f\n", n, nrn_lay2->weight[n]);
            nrn_lay2->som = sms_somme(nrn_lay2->som, nrn_lay1->prob, nrn_lay2->weight[n]);
            nrn_lay2->prob = sms_activation(nrn_lay2->som);
            printf("probability = %f  * %f\n", nrn_lay1->prob, nrn_lay2->weight[n]);
        }
    }
    printf("Somme = %f\n", nrn_lay2->som);
    printf("Activation = %f\n", nrn_lay2->prob);
    return (SUCCESS);
}

int sms_link_model(model_t *model)
{
    layer_t *layer1 = NULL;
    layer_t *layer2 = NULL;
    int i = 0;

    if (model == NULL || model->first == NULL)
        return (ERROR);
    write(1, "Linking Model...\n", 17);
    for (; i < model->nb_layers; i++) {
        if (i > 0) {
            layer1 = sms_find_layer_by_id(model, i - 1);
            layer2 = sms_find_layer_by_id(model, i);
            if (layer1 == NULL || layer2 == NULL)
                break;
            if (sms_link_two_layer_together(layer1, layer2) == ERROR) {
                return (ERROR);
            }
        }
    }
    if (i != model->nb_layers) {
        write(1, "Model Linking : Error\n", 22);
        return(ERROR);
    }
    write(1, "Model Linking : Success\n", 24);
}