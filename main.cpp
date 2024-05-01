/*
   Assignment 4
   Lana Tamim
   Purpose: 
*/

#include <iostream>
#include <list>
#include <cmath>

struct Node {
    double value;
    Node* next;

    Node(double v) : value(v), next(nullptr) {}
};

double value(int position) {
    // 1 << position = 2^position
    return 0.5 / (1 << position);
}

void createNodes(std::list<Node*>& nodes, int numNodes) {
    for (int i = 0; i < numNodes; ++i) {
        nodes.push_back(new Node(value(i)));
    }
}

double activationFunction(double x, double b) {
    return std::abs(std::tanh(x) - b);
}

void printList(const std::list<Node*>& nodes, double b) {
     for (auto x = nodes.begin(); x != nodes.end(); ++x) {
        double activated_value = activationFunction((*x)->value, b);
        std::cout << activated_value;
        if (std::next(x) != nodes.end()) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

double gradientDescent(Node* current, double b, double m) {
    if (current->next == nullptr) {
        // Leaf node
        return activationFunction(current->value, b);
    } else {
        // Traverse successor
        double newSlope = m - pow(10, -current->value);
        // Bias ???
        double newBias = b + current->value / 10.0;
        return gradientDescent(current->next, newBias, newSlope);
    }
}

int main() {
    std::list<Node*> nodes;

    createNodes(nodes, 4);
    double initial_bias = -0.5; // Initial bias
    printList(nodes, initial_bias); // Pass initial bias here

    // Gradient descent operation
    double initial_slope = 0.5; // Initial slope
    double gradient_result = gradientDescent(nodes.front(), initial_bias, initial_slope);
    std::cout << "Gradient: " << gradient_result << std::endl;

    // Output slope and bias values
    std::cout << "Slope: " << initial_slope << std::endl;
    std::cout << "Bias: " << initial_bias << std::endl;

    // Memory cleanup
    for (Node* node : nodes) {
        delete node;
    }

    return 0;
}



/* struct Node {
    double value;
    // Node pointer
    Node* next;
    // Constructor
    Node(double v) : value(v), next(nullptr) {}
};

void printList(const std::list<Node*>& nodes) {
    for (auto x = nodes.begin(); x != nodes.end(); ++x) {
        std::cout << (*x)->value;
        if (std::next(x) != nodes.end()) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

double value(int position) {
    // Generate value: 0.5, 0.25, 0.125, 0.0625
    return 0.5 / (1 << position); // 1 << position = 2^position
}

void createNodes(std::list<Node*>& nodes, int numNodes) {
    for (int i = 0; i < numNodes; ++i) {
        nodes.push_back(new Node(value(i)));
    }
}

double result(Node* current, double slope) {
    if (current->next == nullptr) {
        // Leaf node
        return 0.5;
    } else {
        // Multipy result
        return result(current->next, slope * 0.5);
    }
}

int main() {
    std::list<Node*> nodes;

    // 4 nodes
    createNodes(nodes, 4);
    printList(nodes);

    // Gadient descent operation
    double num = result(nodes.front(), 0.5);
    std::cout << "Gradient: " << num << std::endl;

    // Memory
    for (Node* node : nodes) {
        delete node;
    }

    return 0;
}
*/