#include "Layer.h"

Layer::Layer(int NumberNeurons, int NumberInputsPerNeuron) {
    for (int i = 0; i < NumberNeurons; i++) {
        m_neurons.push_back(Neuron(NumberInputsPerNeuron));
    }
}
