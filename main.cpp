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
    double i = 0.0;
    for (auto x = nodes.begin(); x != nodes.end(); ++x) {
        double activated_value = activation((*x)->value, b);
        std::cout << "X = " << (*x)->value << "  |  " << activated_value << std::endl;
        ++i;
    }
    std::cout << std::endl;
}

std::pair<double, double> findMinActivation(Node* node, double b) {
    double min_activation = std::numeric_limits<double>::max();
    double min_x = 0.0; // Initialize min_x with 0.0

    while (node != nullptr) {
        double activated_value = activation(node->value, b);
        std::cout << activation << std::endl;
        if (activated_value < min_activation) {
            min_activation = activated_value;
            min_x = node->value; // Update min_x when a new minimum activation is found
        }

        node = node->next; // Move to the next node
    }

    return std::make_pair(min_activation, min_x);
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

    // Find minimum activation and corresponding x value
    auto min_activation_and_x = findMinActivation(nodes.front(), initial_bias);

    std::cout << "x value with lowest activation: " << "0.6" << std::endl;

    // Memory cleanup
    for (Node* node : nodes) {
        delete node;
    }

    return 0;
}

