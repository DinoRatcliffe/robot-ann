#include "Network.h"

Network::Network(int NumberInputs, int NumberOutputs, int NumberHiddenLayers, int NeuronsPerHiddenLayer) 
    : m_NumberInputs(NumberInputs), m_NumberOutputs(NumberOutputs), m_NumberHiddenLayers(NumberHiddenLayers), m_NeuronsPerHiddenLayer(NeuronsPerHiddenLayer)
{
    m_layers.push_back(Layer(m_NumberOutputs, m_NeuronsPerHiddenLayer));
    for (int i = 0; i < m_NumberHiddenLayers-1; i++) {
        m_layers.push_back(Layer(m_NeuronsPerHiddenLayer, m_NeuronsPerHiddenLayer));
    }
    m_layers.push_back(Layer(m_NeuronsPerHiddenLayer, m_NumberInputs));
}
