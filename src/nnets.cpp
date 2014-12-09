#include <iostream>
#include <sstream>
#include <fstream>
#include "neuralnet/Neuron.h"
#include "neuralnet/Network.h"

using namespace std;

int main(int argc, const char* argv[])
{
    int num_inputs;
    int num_outputs;
    int num_data_items;
    int num_hidden = atoi(argv[2]);
    int num_neurons_hidden = atoi(argv[3]);
    int iterations = atoi(argv[4]);

    ifstream trainingData(argv[1]); 
    trainingData >> num_data_items;
    trainingData >> num_inputs;
    trainingData >> num_outputs;

    Network net = Network(num_inputs, num_outputs, num_hidden, num_neurons_hidden);
    net.learning_rate = 0.45;
    net.momentum = 0.9;

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
    vector<vector<double> > expected;

    for (int i = 0; i < num_data_items; i++) {
        vector<double> input;
        vector<double> output;
        for (int j = 0; j < num_inputs; j++) {
            double tempInput;
            trainingData >> tempInput;
            input.push_back(tempInput);
        }
        for (int j = 0; j < num_outputs; j++) {
            double tempOutput;
            trainingData >> tempOutput;
            output.push_back(tempOutput);
        }
        inputs.push_back(input);
        expected.push_back(output);
    } 


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

    ifstream testingData(argv[5]);
    int testing_num;
    int input_num;
    int output_num;
    testingData >> testing_num;
    testingData >> input_num;
    testingData >> output_num;

    vector<vector<double> > testing_inputs;
    vector<vector<double> > testing_expected;
    
    for (int i = 0; i < testing_num; i++) {
        vector<double> input;
        vector<double> output;
        for (int j = 0; j < num_inputs; j++) {
            double tempInput;
            testingData >> tempInput;
            input.push_back(tempInput);
        }
        for (int j = 0; j < num_outputs; j++) {
            double tempOutput;
            testingData >> tempOutput;
            output.push_back(tempOutput);
        }
        testing_inputs.push_back(input);
        testing_expected.push_back(output);
    } 

    cout << endl << "=================================" << endl;
    cout << "OUTPUT (t = " << net.getT() << ")" << endl;
    cout << "=================================" << endl;
    for (int i = 0; i < testing_num; i++) {
        cout << "input: " << testing_inputs[i][0] << ", " << testing_inputs[i][1] << endl;
        output = net.update(testing_inputs[i]);
        for (int j = 0; j < output.size(); j++) {
            cout << j+1 << ": " << output[j] << endl;
        }
    }
    cout << "=================================" << endl;
    return 0;
}
