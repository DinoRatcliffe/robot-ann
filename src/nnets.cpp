#include <iostream>
#include "neuralnet/Neuron.h"
#include "neuralnet/Network.h"

using namespace std;

int main()
{
    int num_inputs = 2;
    int num_outputs = 4;
    int num_hidden = 1;
    int num_neurons_hidden = 4;

    Network net = Network(num_inputs, num_outputs, num_hidden, num_neurons_hidden/*, 1417831504*/);

    cout << endl << "=================================" << endl;
    cout << "PARAMETERS" << endl;
    cout << "=================================" << endl;
    cout << "Number Of Inputs: " << num_inputs << endl;
    cout << "Number Of Outputs: " << num_outputs << endl;
    cout << "Number Of Hidden Layers: " << num_hidden << endl;
    cout << "Number Of Neurons in Hidden Layers: " << num_neurons_hidden << endl;
    cout << "Weight Seed: " << net.getSeed() << endl;
    cout << "=================================" << endl;

    vector<double> inputs;
    inputs.push_back(10);
    inputs.push_back(37);

    vector<double> expected;
    expected.push_back(.9);
    expected.push_back(.33);
    expected.push_back(.9339);
    expected.push_back(.9);


    int iterations = 1000;
    net.learning_rate = 0.45;
    net.momentum = 0.9;

    vector<double> output;
    for (int i = 0; i < iterations; i++) {
        output = net.update(inputs);
        net.backpropogate(expected);
    }

    cout << endl << "=================================" << endl;
    cout << "OUTPUT (t = " << net.getT() << ")" << endl;
    cout << "=================================" << endl;
    for (int j = 0; j < output.size(); j++) {
        cout << j+1 << ": " << output[j] << endl;
    }
    cout << "=================================" << endl;

    return 0;
}
