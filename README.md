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

    if (model == NULL)
        return (ERROR);
    for (int i = 0; i < 10; i++) {
        sms_add_layer(model, 4, i);
    }
    sms_print_layer_model(model);
    for (int i = 0; i < 10; i++) {
        sms_print_neuron_layer(model->first);
    }
    sms_rm_model(model);
    return (0);
}
           |
           |
           |
           V
    Valgrind : 0 error 0 context
    Memory : 0 leaks : 91 allocs,91free