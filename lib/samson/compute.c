/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** compute.c
** File description:
** This file contains all the function that
** compute result for neuronal network.
*/

#include "samson.h"

// float retropropagation(layer_t *layer1, float gradient, int i)
// {

//     float biais = 0.0;

//     biais = biais + (gradient * LEARNING_RATE);
//     weight[0] = weight[0] + (gradient * learning_rate * inputs[i][0]);
//     weight[1] = weight[1] + (gradient * learning_rate * inputs[i][1]);
// }

float gradient_descent(model_t *model)
{
    int m = 1;
    int p = 0;
    int result = 0;

    for (int i = 0; i < model->result_wanted[i]; i++) {
        result = model->result_wanted[i];
    }
}

float sms_somme(float som_nrn_lay2, float prob_nrn_lay1, float wgth_nrn_lay2)
{
    som_nrn_lay2 = som_nrn_lay2 + (prob_nrn_lay1 * wgth_nrn_lay2);

    return (som_nrn_lay2);
}

float sms_activation(float som)
{
    float sp = 0.0;
    float activation = 0.0;
    float biais = sms_random_float(-1, 1, 3);

    sp = biais + som;
    activation = 1/(1 + sms_exp(-sp));
    return (activation);
}

float sms_compute_gradient(float ml_activate, float result_activate)
{
    float gradient = 0.0;

    gradient = (result_activate - ml_activate);//invers
    gradient *= gradient;
    return (gradient);
}
