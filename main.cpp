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
    return 0.1 * position;
}

double activation(double x, double b) {
    return std::abs(std::tanh(x) - b);
}

double findMinActivation(const std::list<Node*>& nodes, double b) {
    double minActivation = std::numeric_limits<double>::max();
    
    for (Node* node : nodes) {
        double activatedValue = activation(node->value, b);
        if (activatedValue < minActivation) {
            minActivation = activatedValue;
        }
    }
    
    return minActivation;
}

void printList(const std::list<Node*>& nodes, double b) {
    double minActivation = std::numeric_limits<double>::max();
    double minX = 0.0; // Initialize with a default value
    for (Node* node : nodes) {
        double activatedValue = activation(node->value, b);
        if (activatedValue < minActivation) {
            minActivation = activatedValue;
            minX = node->value; // Update minX to the value of x corresponding to min activation
        }
    }

    for (auto x = nodes.begin(); x != nodes.end(); ++x) {
        double activatedValue = activation((*x)->value, b);
        std::cout << "X = " << (*x)->value << "  |  Activation: " << activatedValue << std::endl;
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

    double initialBias = 0.5; 
    printList(nodes, initialBias);
    
    // output min activation

    // Memory cleanup
    for (Node* node : nodes) {
        delete node;
    }

    return 0;
}
