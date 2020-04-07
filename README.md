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

int main()
{
    model_t *model = sms_init_model();
    int result = SUCCESS;

    if (sms_prepare_model(model) == ERROR)
        return (ERROR);
    result = sms_add_layer(model, 4);
    result = sms_add_layer(model, 4);
    result = sms_add_layer(model, 4);
    result = sms_add_layer(model, 3);
    result = sms_add_layer(model, 1);
    if (result == ERROR)
        return (ERROR);

    result = sms_fit_model(model, 100, "sigmoid");

    sms_print_layer_model(model);
    sms_print_neuron_layer(sms_find_layer_by_id(model, 4));
    sms_rm_model(model);
    return (result);
}

    Valgrind : 0 error 0 context
    Memory : 0 leaks