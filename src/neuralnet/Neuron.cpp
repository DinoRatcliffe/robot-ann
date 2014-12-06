#include "Neuron.h"
#include <iostream>
#include <stdlib.h>

Neuron::Neuron(int NumberInputs) : m_NumberInputs(NumberInputs) {
    //create random weights, plus the bias for variable thresholding
    for (int i = 0; i < NumberInputs+1; i++) {
        m_vectorWeights.push_back(randomWeight());
        m_vectorWeightDeltas.push_back(0);
    }
}

double Neuron::update(vector<double> &inputs) {
    double sum = 0.0;
    for(int i = 0; i < inputs.size(); i++) {
        sum += inputs[i] * m_vectorWeights[i];
    }
    m_previousInputs = inputs;
    m_previousOutput = sigmoid(sum);
    return m_previousOutput;
}

double Neuron::randomWeight() {
    return (rand() % 100 + 1) / 1000.0;
}

double Neuron::error(double targetOutput) {
    m_errordelta = m_previousOutput * (1-m_previousOutput) * (m_previousOutput - targetOutput); 
    return m_errordelta;
}

double Neuron::error(vector<double> &errorweight) {
    double sum = 0;
    for (int i = 0; i < errorweight.size(); i++) {
        sum += errorweight[i];
    }
    m_errordelta = m_previousOutput * (1-m_previousOutput) * sum;
    return m_errordelta;
}

void Neuron::backpropogate(double learnrate, double momentum, double errorDelta) {
    m_vectorWeightDeltasMinus = m_vectorWeightDeltas;
    m_vectorWeightDeltas.clear();
    for (int i = m_vectorWeights.size()-1; i >= 0; i--) {
        double weightdelta = -learnrate * errorDelta * m_previousInputs[i]; //TODO actually fix

//        cout << "old: " << m_vectorWeights[i];
        m_vectorWeights[i] = m_vectorWeights[i] + weightdelta + (momentum * m_vectorWeightDeltasMinus[i]);
//        cout << " new: " << m_vectorWeights[i] << endl;

        m_vectorWeightDeltas.push_back(weightdelta);
    }
}
