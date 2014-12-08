#include "Network.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>

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

Network::Network(string netParams) {
   istringstream iss(netParams);
   iss >> m_t;
   iss >> m_seed;
   iss >> m_NumberInputs;
   iss >> m_NumberOutputs;
   iss >> m_NumberHiddenLayers; 
   iss >> m_NeuronsPerHiddenLayer;

   string s;
   getline(iss, s);
   getline(iss, s);
   m_layers.push_back(Layer(s));
   for (int i = 0; i < m_NumberHiddenLayers; i++) {
       getline(iss, s);
       Layer l = Layer(s);
       m_layers.push_back(l);
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

ostream& operator<<(std::ostream &strm, const Network &net) {
    strm << net.m_t << endl
         << net.m_seed << endl
         << net.m_NumberInputs << endl
         << net.m_NumberOutputs << endl
         << net.m_NumberHiddenLayers << endl
         << net.m_NeuronsPerHiddenLayer << endl;
    for (int i = 0; i < net.m_layers.size(); i++) {
        strm << net.m_layers[i] << endl;
    }
    return strm;
};
