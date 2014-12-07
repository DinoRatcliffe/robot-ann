#include <iostream>
#include "neuralnet/Neuron.h"
#include "neuralnet/Network.h"

using namespace std;

int main()
{
    int num_inputs = 2;
    int num_outputs = 1;
    int num_hidden = 1;
    int num_neurons_hidden = 4;

    int num_data_items = 4;

    Network net = Network(num_inputs, num_outputs, num_hidden, num_neurons_hidden);

    cout << endl << "=================================" << endl;
    cout << "PARAMETERS" << endl;
    cout << "=================================" << endl;
    cout << "Number Of Inputs: " << num_inputs << endl;
    cout << "Number Of Outputs: " << num_outputs << endl;
    cout << "Number Of Hidden Layers: " << num_hidden << endl;
    cout << "Number Of Neurons in Hidden Layers: " << num_neurons_hidden << endl;
    cout << "Weight Seed: " << net.getSeed() << endl;
    cout << "=================================" << endl;

    vector<vector<double> > inputs;
    inputs.push_back(vector<double>());
    inputs.push_back(vector<double>());
    inputs.push_back(vector<double>());
    inputs.push_back(vector<double>());
    inputs.push_back(vector<double>());

    inputs[0].push_back(1);
    inputs[0].push_back(2);
    inputs[1].push_back(3);
    inputs[1].push_back(2);
    inputs[2].push_back(2);
    inputs[2].push_back(1);
    inputs[3].push_back(4);
    inputs[3].push_back(5);
    inputs[4].push_back(1);
    inputs[4].push_back(1);

    vector<vector<double> > expected;
    expected.push_back(vector<double>());
    expected.push_back(vector<double>());
    expected.push_back(vector<double>());
    expected.push_back(vector<double>());

    expected[0].push_back(0.3);
    expected[1].push_back(0.5);
    expected[2].push_back(0.3);
    expected[3].push_back(0.9);

    int iterations = 10000;
    net.learning_rate = 0.45;
    net.momentum = 0.9;

    vector<double> output;
    for (int i = 0; i < iterations; i++) {
        for (int j = 0; j < num_data_items; j++) {
            output = net.update(inputs[j]);
            net.backpropogate(expected[j]);
        }
    }

    cout << endl << "=================================" << endl;
    cout << "OUTPUT (t = " << net.getT() << ")" << endl;
    cout << "=================================" << endl;
    for (int i = 0; i < num_data_items; i++) {
        cout << "input: " << inputs[i][0] << ", " << inputs[i][1] << endl;
        output = net.update(inputs[i]);
        for (int j = 0; j < output.size(); j++) {
            cout << j+1 << ": " << output[j] << endl;
        }
    }
    cout << "=================================" << endl;
    cout << net << endl;
    
        cout << "input: " << inputs[4][0] << ", " << inputs[4][1] << endl;
        output = net.update(inputs[4]);
        for (int j = 0; j < output.size(); j++) {
            cout << j+1 << ": " << output[j] << endl;
        }

    return 0;
}
