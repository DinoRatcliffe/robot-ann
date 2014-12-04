#include <iostream>
#include "neuralnet/Neuron.h"
#include "neuralnet/Network.h"

using namespace std;

int main()
{
    cout << "Hello World!\n";
    Network net = Network(4, 2, 2, 4);
    cout << "Layers: " << net.getLayers().size() << endl;
    return 0;
}
