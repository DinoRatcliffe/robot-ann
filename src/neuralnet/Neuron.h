#ifndef _NEURON_H_
#define _NEURON_H_

#include <vector>

using namespace std;

class Neuron {
    public:
        Neuron(int NumberInputs);
        int getNumberInputs() { return m_NumberInputs; };
        vector<double> getVectorWeights() { return m_vectorWeights; };
        void setVectorWeights(vector<double> newVectorWeights) { m_vectorWeights = newVectorWeights; };
    private:
        int m_NumberInputs;
        vector<double> m_vectorWeights;
        static double randomWeight();
};

#endif
