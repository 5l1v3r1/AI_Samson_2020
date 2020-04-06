# AI_Samson_2020



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