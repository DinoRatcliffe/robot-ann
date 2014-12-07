#include "Layer.h"
#include <iostream>

Layer::Layer(int NumberNeurons, int NumberInputsPerNeuron) : m_NumberNeurons(NumberNeurons) {
    for (int i = 0; i < NumberNeurons; i++) {
        m_neurons.push_back(Neuron(NumberInputsPerNeuron));
    }
}

Layer::Layer(string layerParams) {
    cout << "layerparams" << endl;
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
    for(int i = 0; i < layer.m_NumberNeurons; i++) { 
        strm << layer.m_neurons[i] << endl;
    }
    return strm;
}
