# AI_Samson_2020


ACTUALLY:
Need to :
-link eatch neuron between each oser.
-compute gradient, biais...
-create int_encoder
-create bin_encoder
-create strenght_encoder


exemple of use :

#include "samson.h"
#include <time.h>

float *dataset(void)
{
    float *dataset = NULL;

    dataset = malloc(sizeof(float) * 2);
    if (dataset == NULL)
        return (NULL);
    dataset[0] = 1;
    dataset[1] = 1;
    return (dataset);
}

int main()
{
    model_t *model = sms_init_model(2, 1);
    int result = SUCCESS;
    srand(time(NULL));
    float *data = dataset();
    int lenght_dataset = 2;

    if (data == NULL)
        return (ERROR);
    if (model == NULL)
        return (ERROR);
    result = sms_add_layer(model, 2);
    result = sms_add_layer(model, 1);
    if (result == ERROR)
        return (ERROR);
    result = sms_fit_model(model, 1, "sigmoid", data, lenght_dataset);
    sms_print_layer_model(model);
    sms_print_neuron_layer(sms_find_layer_by_id(model, 4));
    sms_rm_model(model);
    return (result);
}

    Valgrind : 0 error 0 context
    Memory : 0 leaks