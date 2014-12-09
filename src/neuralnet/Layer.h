#ifndef _LAYER_H_
#define _LAYER_H_

#include <vector>
#include "Neuron.h"
#include <iostream>
#include <string>

using namespace std;

class Layer {
    public:
        vector<Neuron> m_neurons;
        Layer(int NumberNeurons, int NumberInputsPerNeuron);
        Layer(string layerParams);
        int getNumberNeurons() { return m_NumberNeurons; };
        vector<double> update(vector<double> &inputs);
        Layer& backpropogate(Layer &nxtLayer, double learnrate, double momentum);
        Layer& backpropogate(double learnrate, double momentum, vector<double> &targetOuput);
    private:
        friend ostream& operator<<(std::ostream &strm, const Layer &layer);
        int m_NumberNeurons;
};

#endif
