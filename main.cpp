/*
   Assignment 4
   Lana Tamim
   Purpose: Make a list that gradually decreases by 0.5
*/

#include <iostream>
#include <list>

struct Node {
    double value;
    Node* next;

    Node(double v) : value(v), next(nullptr) {}
};

void printList(const std::list<Node*>& nodes) {
    for (auto it = nodes.begin(); it != nodes.end(); ++it) {
        std::cout << (*it)->value;
        if (std::next(it) != nodes.end()) {
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
        // Leaf node, return 1/2
        return 0.5;
    } else {
        // Multiply the result by slope
        return result(current->next, slope * 0.5);
    }
}

int main() {
    std::list<Node*> nodes;

    // 4 nodes
    createNodes(nodes, 4);

    printList(nodes);

    // Gadient descent operation
    double result = result(nodes.front(), 0.5);
    std::cout << "Gradient: " << result << std::endl;

    // Memory
    for (Node* node : nodes) {
        delete node;
    }

    return 0;
}
