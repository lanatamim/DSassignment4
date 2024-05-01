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

void printList(const std::list<Node*>& nodes) {
    for (auto x = nodes.begin(); x != nodes.end(); ++x) {
        std::cout << (*x)->value << std::endl;
    }
}

double leafNodeValue(double x) {
    // Computes value for a leaf node based on the given formula
    return 0.5 * std::tanh(x);
}

void createNodes(std::list<Node*>& nodes, int numNodes) {
    // Generate nodes and calculates their values
    for (int i = 0; i < numNodes; ++i) {
        double value = i == 0 ? 0.5 : leafNodeValue(nodes.back()->value);
        nodes.push_back(new Node(value));
    }
}

int main() {
    std::list<Node*> nodes;

    // Create 4 nodes and print their values
    createNodes(nodes, 4);
    printList(nodes);

    // Memory
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