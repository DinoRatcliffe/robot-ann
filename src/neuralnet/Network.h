#ifndef _NETWORK_H_ 
#define _NETWORK_H_

#include <vector>
#include "Layer.h"
#include <time.h>

using namespace std;

class Network {
    public:
       Network(int NumberInputs, int NumberOutputs, int NumberHiddenLayers, int NeuronsPerHiddenLayer, int seed = time(NULL));
       vector<double> getWeights() const;
       int getNumberOfWeights() const;
       double momentum, learning_rate;
       void putWeights(vector<double> &weights);
       vector<double> update(vector<double> &inputs);
       inline double Sigmoid(double activation, double response);
       vector<Layer> getLayers() { return m_layers; };
       int getSeed() { return m_seed; };
       int getT() { return m_t; };
       void backpropogate(vector<double> &target_output);
    private:
       int m_NumberInputs;
       int m_NumberOutputs;
       int m_NumberHiddenLayers;
       int m_NeuronsPerHiddenLayer;
       int m_seed;
       int m_t;

       vector<Layer> m_layers;
};

#endif
