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

void printList(const std::list<Node*>& nodes, double b) {
     double i = 0.0;
     for (auto it = nodes.begin(); it != nodes.end(); ++it) {
          double activatedValue = activation((*it)->value, b);
          std::cout << "X = " << (*it)->value << "  |  " << activatedValue << std::endl;
          ++i;
     }
     std::cout << std::endl;
}

// Find the minimum activation value and the corresponding x value
std::pair<double, double> min(Node* node, double b, double m, double minNum, double x) {
     if (node == nullptr) {
          return std::make_pair(minNum, x);
     }

     double activatedValue = activation(node->value, b);
     if (activatedValue < minNum) {
          minNum = activatedValue;
          x = node->value;
     }

     // Update slope
     double newSlope = m - (10 - node->value);
     // Adjust bias
     double newBias = b + node->value / 10.0;

     return min(node->next, newBias, newSlope, minNum, x);
}

int main() {
     int iterations = 11;
     std::list<Node*> nodes;

     // Create nodes and iterate
     for (int i = 0; i < iterations; ++i) {
          nodes.push_back(new Node(value(i)));
     }

     double initialBias = 0.5; 
     printList(nodes, initialBias);

     // Gradient descent
     double initialSlope = 1.0;
     double initialMinNum = std::numeric_limits<double>::max();
     // Initialize x to the first node value
     double initialX = nodes.front()->value;
     auto minNumAndX = min(nodes.front(), initialBias, initialSlope, initialMinNum, initialX);

     std::cout << "x value with the least error: " << minNumAndX.second << std::endl;

     // Memory cleanup
     for (Node* node : nodes) {
          delete node;
     }

     return 0;
}
