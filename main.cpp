/*
   Assignment 4
   Lana Tamim
*/

#include <iostream>
#include <list>
#include <cmath>
#include <limits>

struct Node {
    double value;
    Node* next;

    Node(double v) : value(v), next(nullptr) {}
};

double value(int position) {
    // 1 << position = 2^position
    return 0.1 * position;
}

double activation(double x, double b) {
    return std::abs(std::tanh(x) - b);
}

// find min activation 
/*
If leaf node (ie, if successor is nullpointer)
– Calculate activation function: abs[tanh (x) – b]
▪ Else
– Traverse successor node with arglist s.t. m is less steep by 10-x

Derive and return result
*/
double findMinActivation(const std::list<Node*>& nodes, double b) {
    double minActivation = std::numeric_limits<double>::max(); // Initialize with maximum possible value
    
    for (Node* node : nodes) {
        double activated_value = activation(node->value, b);
        if (activated_value < minActivation) {
            minActivation = activated_value;
        }
    }
    
    return minActivation;
}

void printList(const std::list<Node*>& nodes, double b) {
    double minActivation = std::numeric_limits<double>::max();
    double minX = 0.0; // Initialize with a default value
    for (Node* node : nodes) {
        double activated_value = activation(node->value, b);
        if (activated_value < minActivation) {
            minActivation = activated_value;
            minX = node->value; // Update minX to the value of x corresponding to min activation
        }
    }

    for (auto x = nodes.begin(); x != nodes.end(); ++x) {
        double activated_value = activation((*x)->value, b);
        std::cout << "X = " << (*x)->value << "  |  Activation: " << activated_value << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Minimum Activation: " << minActivation << " at X = " << minX << std::endl;
}





int main() {
    int numNodes = 11;
    std::list<Node*> nodes;

    // Create nodes
    for (int i = 0; i < numNodes; ++i) {
        nodes.push_back(new Node(value(i)));
    }

    double initial_bias = 0.5; 
    printList(nodes, initial_bias);
    
    // output min activation

    // Memory cleanup
    for (Node* node : nodes) {
        delete node;
    }

    return 0;
}

