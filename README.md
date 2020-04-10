# AI_Samson_2020

ACTUALLY:
Have :
-Build model.
-Build layers.
-Build eatch neuron together.
-Copute som, compute activation, biais (only sigmoid right now).
-For the moment the regression decision is only made by a if.

Need to :
-Gradient Descent.
-Build int_encoder.
-Build bin_encoder.
-Build strenght_encoder.
-Scale function (make clear code :)  )
-Build matrix output that compare result_user with result_ml.
-Build feature name 'Hot_Save' that print each information at each moment in
a mem file.


exemple of use :

#include "samson.h"
#include <time.h>

float *dataset(void)
{
    float *dataset = NULL;

    dataset = malloc(sizeof(float) * 2);
    if (dataset == NULL)
        return (NULL);
    dataset[0] = 0.543;
    dataset[1] = 0.653;
    return (dataset);
}

int main()
{
    int result = SUCCESS;
    srand(time(NULL));
    int lenght_dataset = 2;
    int nb_output = 1;
    model_t *model = sms_init_model(lenght_dataset, nb_output);
    float *data = dataset();
    float *result_data = dataset();

    if (data == NULL || result_data == NULL)
        return (ERROR);
    if (model == NULL)
        return (ERROR);
    result_data[0] = 0;
    result = sms_add_layer(model, lenght_dataset);
    result = sms_add_layer(model, nb_output);
    if (result == ERROR)
        return (ERROR);
    result = sms_fit_model(model, 100, "sigmoid", data, result_data, lenght_dataset);
    sms_print_layer_model(model);
    printf("OUTPUT LAYER = \n");
    for (int i = 0; i < nb_output; i++)
        printf("%f\n", model->output_set[i]);
    if (model->output_set[0] > 0.5)
        my_putstr("TRUE\n");
    else
        my_putstr("FALSE\n");
    sms_rm_model(model);
    free(result_data);
    free(data);
    return (result);
}
    Valgrind : 0 error 0 context
    Memory : 0 leaks