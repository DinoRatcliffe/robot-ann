#ifndef _LAYER_H_
#define _LAYER_H_

#include <vector>
#include "Neuron.h"

using namespace std;

class Layer {
    public:
        vector<Neuron> m_neurons;
        Layer(int NumberNeurons, int NumberInputsPerNeuron);
        int getNumberNeurons() { return m_NumberNeurons; };
        vector<double> update(vector<double> &inputs);
        Layer& backpropogate(Layer &nxtLayer, double learnrate, double momentum);
        Layer& backpropogate(double learnrate, double momentum, vector<double> &targetOuput);
    private:
        int m_NumberNeurons;
};

#endif
