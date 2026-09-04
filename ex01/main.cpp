#include "Span.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
    std::cout << "--- Testing Subject Example ---" << std::endl;
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n--- Testing Exception: Full Span ---" << std::endl;
    try {
        sp.addNumber(42);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- Testing Exception: Not Enough Numbers ---" << std::endl;
    Span emptySpan(5);
    try {
        emptySpan.shortestSpan();
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- Testing 20,000 Numbers (Range Iterator) ---" << std::endl;
    Span massiveSpan(20000);
    std::vector<int> massiveVector;

    for (int i = 0; i < 20000; ++i) {
        massiveVector.push_back(i * 3);
    }

    massiveSpan.addNumber(massiveVector.begin(), massiveVector.end());

    std::cout << "Shortest span (should be 3): " << massiveSpan.shortestSpan() << std::endl;
    std::cout << "Longest span (should be 59997): " << massiveSpan.longestSpan() << std::endl;

    return 0;
}
