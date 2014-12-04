#ifndef _NETWORK_H_ 
#define _NETWORK_H_

#include <vector>
#include "Layer.h"

using namespace std;

class Network {
    public:
       Network(int NumberInputs, int NumberOutputs, int NumberHiddenLayers, int NeuronsPerHiddenLayer);
       vector<double> getWeights() const;
       int getNumberOfWeights() const;
       void putWeights(vector<double> &weights);
       vector<double> Update(vector<double> &inputs);
       inline double Sigmoid(double activation, double response);
       vector<Layer> getLayers() { return m_layers; };
    private:
       int m_NumberInputs;
       int m_NumberOutputs;
       int m_NumberHiddenLayers;
       int m_NeuronsPerHiddenLayer;

       vector<Layer> m_layers;
};

#endif
