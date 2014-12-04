#include "Neuron.h"
#include <iostream>

Neuron::Neuron(int NumberInputs) : m_NumberInputs(NumberInputs) {
    //create random weights, plus the bias for variable thresholding
    for (int i = 0; i < NumberInputs+1; i++) {
        m_vectorWeights.push_back(randomWeight());
    }
}

double Neuron::randomWeight() {
    return 1;
}
