#include "Network.h"
#include <iostream>
#include <stdlib.h>

Network::Network(int NumberInputs, int NumberOutputs, int NumberHiddenLayers, int NeuronsPerHiddenLayer, int seed) 
    : m_NumberInputs(NumberInputs), m_NumberOutputs(NumberOutputs), m_NumberHiddenLayers(NumberHiddenLayers), m_NeuronsPerHiddenLayer(NeuronsPerHiddenLayer), m_seed(seed)
{
    srand(m_seed);
    m_t = 0;
    m_layers.push_back(Layer(m_NumberOutputs, m_NeuronsPerHiddenLayer));
    for (int i = 0; i < m_NumberHiddenLayers; i++) {
        m_layers.push_back(Layer(m_NeuronsPerHiddenLayer, m_NeuronsPerHiddenLayer));
    }
}

vector<double> Network::update(vector<double> &inputs) {    
    vector<double> result = inputs;
    for (int i = m_layers.size()-1; i >= 0; i--) {
       result = m_layers[i].update(result); 
    }
    m_t++;
    return result;
}

void Network::backpropogate(vector<double> &target_output) {
    m_layers[0].backpropogate(learning_rate, momentum, target_output);
    for (int i = 1; i < m_layers.size(); i++) {
        m_layers[i].backpropogate(m_layers[i-1], learning_rate, momentum);
    }
}
