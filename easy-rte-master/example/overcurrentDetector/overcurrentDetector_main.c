#include "F_overcurrentDetector.h"
#include <stdio.h>

void print_data(uint64_t t, inputs_overcurrentDetector_t inputs, outputs_overcurrentDetector_t outputs) {
    printf("Time: %lu ms\tCurrent:%6d mA\tRelay: %s\r\n", t/1000, inputs.I_mA, outputs.relay_en ? "enabled":"DISABLED");
}

//remember to change template timer t++ to t+=1000 for the purposes of this demo
//here, each tick represents 1 millisecond.
int main() {
    enforcervars_overcurrentDetector_t enf;
    inputs_overcurrentDetector_t inputs;
    outputs_overcurrentDetector_t outputs;
    
    overcurrentDetector_init_all_vars(&enf, &inputs, &outputs);
    inputs.I_mA = 1000;
    outputs.relay_en = 1;
    uint64_t t = 0;
    while(t < 180000) {
        t+= 1000;

        if(t == 5000) {
            inputs.I_mA = 10000;
        } 

        if(outputs.relay_en == 0) {
            inputs.I_mA = 0;
        }

        overcurrentDetector_run_via_enforcer(&enf, &inputs, &outputs);

        print_data(t, inputs, outputs);
    }
}

void overcurrentDetector_run(inputs_overcurrentDetector_t *inputs, outputs_overcurrentDetector_t *outputs) {
    
}

