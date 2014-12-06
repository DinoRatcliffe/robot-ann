#ifndef _NEURON_H_
#define _NEURON_H_

#include <vector>
#include <stdlib.h>

using namespace std;

class Neuron {
    public:
        Neuron(int NumberInputs);
        int getNumberInputs() { return m_NumberInputs; };
        vector<double> getVectorWeights() { return m_vectorWeights; };
        void setVectorWeights(vector<double> newVectorWeights) { m_vectorWeights = newVectorWeights; };
        vector<double> m_vectorWeightDeltas;
        vector<double> m_vectorWeightDeltasMinus;
        double update(vector<double> &inputs);
        double error(vector<double> &errorweight);
        double error(double targetOutput);
        void backpropogate(double learnrate, double momentum, double errorDelta);
        double sigmoid(double x) { return x / (1 + abs(x)); };
        double getErrorDelta() { return m_errordelta; }
    private:
        int m_NumberInputs;
        vector<double> m_vectorWeights;
        static double randomWeight();
        vector<double> m_previousInputs;
        double m_previousOutput;
        double m_errordelta;
};

#endif
