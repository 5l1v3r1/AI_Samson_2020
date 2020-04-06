/*
** BELAHOUEL LABORATORY'S PROJECT, 2020
** compute.c
** File description:
** This file contains all the function that
** compute result for neuronal network.
*/


// float retropropagation(char *inputs, float gradient, int i)
// {
//     float biais = biais + (gradient * LEARNING_RATE)
//     weight[0] = weight[0] + (gradient * learning_rate * inputs[i][0])
//     weight[1] = weight[1] + (gradient * learning_rate * inputs[i][1])
// }

// float activation(char *inputs, int i)
// {
//     float sp = 0.0;

//     sp = biais + (inputs[i][0] * weight[0]) + (inputs[i][1] * weight[1])
//     self._activate = 1/(1 + sms_exp(-sp))
// }

// float compute_gradient(char *output, float activate, int i)
// {
//     float gradient = output[i] - activate;
// }

neuron_t init_neuron(neuron_t neuron)
{

}

// void init_layer(neuron_t *layer, int nb_unit)
// {
//     for (int i = 0; i < nb_unit; i++) {
//         init_neuron(layer->)
//     }

// }

model_t sms_model(int nb_inputs, int nb_output, int nb_layers)
{
    neuron_t *layer = malloc(sizeof(neuron_t) * nb_inputs);
    layer->

    return (model);
}

int main(int argc, char **argv)
{
    char **dataset = NULL;
    char **int_dataset = NULL;
    char inputs[4][2] = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
    char output[4] = {0, 0, 0, 1};
    int gen = 500;
    int nb_unit = 4;
    model_t model = sms_model(4, 1, 3);
    neuron_t *layer1 = malloc(sizeof(neuron_t) * nb_unit);


    // init_layer(&layer1, nb_unit);

// LOAD DATA
    // dataset = sms_open_csv("data/qualification_round.csv");

//ENCODE DATA
    // int_dataset = sms_int_encoder(dataset);

// //PRINT FIRST LINE TRAINING
    // sms_display_model(0, 500, 0);

// //TRAINING
//     for (int i = 0; i < gen; i++) {
//         printf("| GENERATION %d / %d                                   |\n", i + 1, gen);
//     }

// //PRINT LAST LINE AFTER TRAINING
//     sms_display_model(0, 500, 1);





    free(layer1);
    // for (int i = 0; dataset[i] != NULL; i++)
    //     free(dataset[i]);
    // free(dataset);
    return (0);
}
