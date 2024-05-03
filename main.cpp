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

void printList(const std::list<Node*>& nodes, double b) {
    int i = 0;
    for (auto x = nodes.begin(); x != nodes.end(); ++x) {
        double activated_value = activation((*x)->value, b);
        std::cout << "X = " << (*x)->value << "  |  " << activated_value << std::endl;
        ++i;
    }
    std::cout << std::endl;
}

std::pair<double, double> findMinActivation(Node* current, double b, double m, double min_activation, double min_x) {
    // Calculate activation value for the current node
    double activated_value = activation(current->value, b);

    // Check if the current activation value is smaller than the minimum activation found so far
    if (activated_value < min_activation) {
        min_activation = activated_value;
        min_x = current->value;
    }

    // If there's a successor node, continue traversing the list recursively
    if (current->next != nullptr) {
        // Update slope and bias for the next node
        double newSlope = m - pow(10, -current->value);
        double newBias = b + current->value / 10.0;

        // Recursively call the function for the next node
        std::pair<double, double> result = findMinActivation(current->next, newBias, newSlope, min_activation, min_x);

        // Update minimum activation and corresponding x value based on the result from the next node
        min_activation = result.first;
        min_x = result.second;
    }

    return {min_activation, min_x};
}


int main() {
    int numNodes = 11;
    std::list<Node*> nodes;

    // Create nodes
    for (int i = 0; i < numNodes; ++i) {
        nodes.push_back(new Node(value(i)));
    }

    double initial_bias = 0.5; 
    std::cout << "Initial Bias: " << initial_bias << std::endl;
    printList(nodes, initial_bias);

    // Gradient descent
    double initial_slope = 1.0;
    double initial_min_activation = std::numeric_limits<double>::max();
    // Find the minimum value and output
    auto min_activation_and_x = findMinActivation(nodes.front(), initial_bias, initial_slope, initial_min_activation, 0.0);
    std::cout << "x value with lowest activation: " << min_activation_and_x.second << std::endl;

    // Memory cleanup
    for (Node* node : nodes) {
        delete node;
    }

    return 0;
}

// back propagation
// azumit o.6
// iterations 11
// increment 0.1
// activation abs::tanh(x)
// passing down x value after activation
// get the min result
// caller multiplies it by n and returns x
// double azimuth[] = {0.0, - 1.0}
// x = 0.0 b = 0.5 m = 1.0
// 0.037

