#include "Layer.h"
#include <iostream>
#include <sstream>

Layer::Layer(int NumberNeurons, int NumberInputsPerNeuron) : m_NumberNeurons(NumberNeurons) {
    for (int i = 0; i < NumberNeurons; i++) {
        m_neurons.push_back(Neuron(NumberInputsPerNeuron));
    }
}

Layer::Layer(string layerParams) {
    istringstream iss(layerParams);
    iss >> m_NumberNeurons;
    int numInputs;
    for (int i = 0; i < m_NumberNeurons; i++) {
       iss >> numInputs;
       vector<double> newNeuron;
       double temp;
       for (int j = 0; j < numInputs; j++) {
           iss >> temp;
           newNeuron.push_back(temp);
       } 
       m_neurons.push_back(Neuron(numInputs-1, newNeuron));
    }
}

vector<double> Layer::update(vector<double> &inputs) {
    vector<double> output;
    for (int i = m_NumberNeurons-1; i >= 0; i--) {
        output.push_back(m_neurons[i].update(inputs));
    }
    return output;
}

Layer& Layer::backpropogate(Layer &nxtLayer, double learnrate, double momentum) {
    for(int i = 0; i < m_NumberNeurons; i++) {
        vector<double> errorweights;
        for(int j = 0; j < nxtLayer.m_NumberNeurons; j++) {
            errorweights.push_back(nxtLayer.m_neurons[j].getErrorDelta() * nxtLayer.m_neurons[j].getVectorWeights()[i]);
        }
        m_neurons[i].backpropogate(learnrate, momentum, m_neurons[i].error(errorweights));
    }
    return *this;
}

Layer& Layer::backpropogate(double learnrate, double momentum, vector<double> &targetOuput) {
    for(int i = 0; i < m_NumberNeurons; i++) {
        m_neurons[i].backpropogate(learnrate, momentum, m_neurons[i].error(targetOuput[i]));
    }
    return *this;
}

ostream& operator<<(ostream &strm, const Layer &layer) {
    strm << layer.m_NumberNeurons << " ";
    for(int i = 0; i < layer.m_NumberNeurons; i++) { 
        strm << layer.m_neurons[i];
    }
    return strm;
}
